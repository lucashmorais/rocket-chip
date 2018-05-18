#include "VPicosManager.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cassert>
#include <iostream>
#include <random> 
#include <queue>
#include <string>

using namespace std;

mt19937 rng;
uniform_int_distribution<mt19937::result_type> dist(1, 100000);
uniform_int_distribution<mt19937::result_type> cycle_dist(0, 255);
IData ** subQueuesBits;
CData ** subQueuesValids;
CData ** subQueuesReadies;
IData ** readyQueuesBits;
CData ** readyQueuesValids;
CData ** readyQueuesReadies;

class packetInfo {
public:
  int sourceIdx;
  int payload;

  packetInfo (int idx, int data) {
    sourceIdx = idx;
    payload = data;
  }

  packetInfo (int idx) {
    sourceIdx = idx;
  }
};

void success() {
  cout << "Success!" << endl;
  exit(0);
}

/*
 * Returns -1 if write was not successful and subqIndex otherwise.
 */
int sendRandomPackage(VPicosManager* top, int subqIndex) {
  static bool first = true;
  static int count;

  for (int i = 0; i < 4; i++)
    *subQueuesValids[i] = 0;

  if (!first && count-- > 0) {
    return -1;
  }
  else {
    first = false;
    count = cycle_dist(rng);
  }

  if (*subQueuesReadies[subqIndex] == 0)
    return -1;
  
  unsigned int randomPacket = dist(rng);
  //cout << "Package to be sent to SubQ " << subqIndex << ": " << randomPacket << endl;

  *subQueuesBits[subqIndex] = randomPacket;
  *subQueuesValids[subqIndex] = 1;
  return randomPacket;
}

/*
 * Returns -1 if read was not successful and subqIndex otherwise.
 */
packetInfo getPackage(VPicosManager* top, int readyqIndex) {
  static bool first = true;
  static int count;

  for (int i = 0; i < 4; i++)
    *readyQueuesReadies[i] = 0;

  if (!first && count-- > 0) {
    return packetInfo(-1);
  }
  else {
    first = false;
    count = cycle_dist(rng);
  }

  if (*readyQueuesValids[readyqIndex] == 0)
    return packetInfo(-1);

  unsigned int packet = *readyQueuesBits[readyqIndex];

  *readyQueuesReadies[readyqIndex] = 1;
  //cout << "Package got from RunQ " << readyqIndex << ": " << packet << endl;
  return packetInfo(readyqIndex, packet);
}

int main(int argc, char **argv, char **env) {
  int clock;

  rng.seed(random_device()());

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  VPicosManager* top = new VPicosManager;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("PicosManager.vcd");

  subQueuesBits = new IData * [4] {&top->io_subQInterface_0_bits, &top->io_subQInterface_1_bits, &top->io_subQInterface_2_bits, &top->io_subQInterface_3_bits};
  subQueuesValids = new CData * [4] {&top->io_subQInterface_0_valid, &top->io_subQInterface_1_valid, &top->io_subQInterface_2_valid, &top->io_subQInterface_3_valid};
  subQueuesReadies = new CData * [4] {&top->io_subQInterface_0_ready, &top->io_subQInterface_1_ready, &top->io_subQInterface_2_ready, &top->io_subQInterface_3_ready};
  readyQueuesBits = new IData * [4] {&top->io_readyQInterface_0_bits, &top->io_readyQInterface_1_bits, &top->io_readyQInterface_2_bits, &top->io_readyQInterface_3_bits};
  readyQueuesValids = new CData * [4] {&top->io_readyQInterface_0_valid, &top->io_readyQInterface_1_valid, &top->io_readyQInterface_2_valid, &top->io_readyQInterface_3_valid};
  readyQueuesReadies = new CData * [4] {&top->io_readyQInterface_0_ready, &top->io_readyQInterface_1_ready, &top->io_readyQInterface_2_ready, &top->io_readyQInterface_3_ready};

  // initialize simulation inputs
  top->clock = 1;
  top->reset = 0;

  uniform_int_distribution<mt19937::result_type> queueDist(0, 3);

  queue <packetInfo> infoQueue;

  int i = 0;
  int numPacketsToSend = 100;

  if (argc > 1)
    numPacketsToSend = stoi(argv[1]);

  cout << "Testing the random emission of " << numPacketsToSend << " packets." << endl;

  int numPacketsToReceive = numPacketsToSend;
  while (true) {
    if (numPacketsToReceive == 0)
      break;

    top->reset = (i < 2);

    long int queueToTest = queueDist(rng);

    if (numPacketsToSend > 0) {
      int packetSent = sendRandomPackage(top, queueToTest);

      if (packetSent >= 0) {
        infoQueue.push(packetInfo(queueToTest, packetSent));
        numPacketsToSend--;
      }
    }

    if (!infoQueue.empty()) {
      packetInfo packetGot = getPackage(top, infoQueue.front().sourceIdx);

      //cout << "Trying to get a packet from queue " << infoQueue.front().sourceIdx << endl;
      if (packetGot.sourceIdx >= 0) {
        assert(infoQueue.front().payload == packetGot.payload);

        infoQueue.pop();
        numPacketsToReceive--;
      }
    }

    // dump variables into VCD file and toggle clock
    for (clock=0; clock<2; clock++) {
      tfp->dump (2*i+clock);
      top->clock = !top->clock;
      top->eval ();
    }

    if (Verilated::gotFinish())  success();
    i++;
  }

  tfp->close();
  success();
}
