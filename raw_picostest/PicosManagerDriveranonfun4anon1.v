`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif

module Queue(
  input         clock,
  input         reset,
  output        io_enq_ready,
  input         io_enq_valid,
  input  [31:0] io_enq_bits,
  input         io_deq_ready,
  output        io_deq_valid,
  output [31:0] io_deq_bits
);
  reg [31:0] ram [0:15];
  reg [31:0] _RAND_0;
  wire [31:0] ram__T_43_data;
  wire [3:0] ram__T_43_addr;
  wire [31:0] ram__T_29_data;
  wire [3:0] ram__T_29_addr;
  wire  ram__T_29_mask;
  wire  ram__T_29_en;
  reg [3:0] value;
  reg [31:0] _RAND_1;
  reg [3:0] value_1;
  reg [31:0] _RAND_2;
  reg  maybe_full;
  reg [31:0] _RAND_3;
  wire  _T_20;
  wire  _T_22;
  wire  _T_23;
  wire  _T_24;
  wire  _T_25;
  wire  _T_27;
  wire [4:0] _T_32;
  wire [3:0] _T_33;
  wire [3:0] _GEN_4;
  wire [4:0] _T_36;
  wire [3:0] _T_37;
  wire [3:0] _GEN_5;
  wire  _T_38;
  wire  _GEN_6;
  wire  _T_40;
  wire  _T_42;
  assign io_enq_ready = _T_42;
  assign io_deq_valid = _T_40;
  assign io_deq_bits = ram__T_43_data;
  assign ram__T_43_addr = value_1;
  assign ram__T_43_data = ram[ram__T_43_addr];
  assign ram__T_29_data = io_enq_bits;
  assign ram__T_29_addr = value;
  assign ram__T_29_mask = _T_25;
  assign ram__T_29_en = _T_25;
  assign _T_20 = value == value_1;
  assign _T_22 = maybe_full == 1'h0;
  assign _T_23 = _T_20 & _T_22;
  assign _T_24 = _T_20 & maybe_full;
  assign _T_25 = io_enq_ready & io_enq_valid;
  assign _T_27 = io_deq_ready & io_deq_valid;
  assign _T_32 = value + 4'h1;
  assign _T_33 = _T_32[3:0];
  assign _GEN_4 = _T_25 ? _T_33 : value;
  assign _T_36 = value_1 + 4'h1;
  assign _T_37 = _T_36[3:0];
  assign _GEN_5 = _T_27 ? _T_37 : value_1;
  assign _T_38 = _T_25 != _T_27;
  assign _GEN_6 = _T_38 ? _T_25 : maybe_full;
  assign _T_40 = _T_23 == 1'h0;
  assign _T_42 = _T_24 == 1'h0;
`ifdef RANDOMIZE
  integer initvar;
  initial begin
    `ifndef verilator
      #0.002 begin end
    `endif
  _RAND_0 = {1{$random}};
  `ifdef RANDOMIZE_MEM_INIT
  for (initvar = 0; initvar < 16; initvar = initvar+1)
    ram[initvar] = _RAND_0[31:0];
  `endif // RANDOMIZE_MEM_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {1{$random}};
  value = _RAND_1[3:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_2 = {1{$random}};
  value_1 = _RAND_2[3:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_3 = {1{$random}};
  maybe_full = _RAND_3[0:0];
  `endif // RANDOMIZE_REG_INIT
  end
`endif // RANDOMIZE
  always @(posedge clock) begin
    if(ram__T_29_en & ram__T_29_mask) begin
      ram[ram__T_29_addr] <= ram__T_29_data;
    end
    if (reset) begin
      value <= 4'h0;
    end else begin
      if (_T_25) begin
        value <= _T_33;
      end
    end
    if (reset) begin
      value_1 <= 4'h0;
    end else begin
      if (_T_27) begin
        value_1 <= _T_37;
      end
    end
    if (reset) begin
      maybe_full <= 1'h0;
    end else begin
      if (_T_38) begin
        maybe_full <= _T_25;
      end
    end
  end
endmodule
module PicosManagerDriveranonfun4anon1(
  input         clock,
  input         reset,
  output        io_subQInterface_0_ready,
  input         io_subQInterface_0_valid,
  input  [31:0] io_subQInterface_0_bits,
  output        io_subQInterface_1_ready,
  input         io_subQInterface_1_valid,
  input  [31:0] io_subQInterface_1_bits,
  output        io_subQInterface_2_ready,
  input         io_subQInterface_2_valid,
  input  [31:0] io_subQInterface_2_bits,
  output        io_subQInterface_3_ready,
  input         io_subQInterface_3_valid,
  input  [31:0] io_subQInterface_3_bits,
  input         io_readyQInterface_0_ready,
  output        io_readyQInterface_0_valid,
  output [31:0] io_readyQInterface_0_bits,
  input         io_readyQInterface_1_ready,
  output        io_readyQInterface_1_valid,
  output [31:0] io_readyQInterface_1_bits,
  input         io_readyQInterface_2_ready,
  output        io_readyQInterface_2_valid,
  output [31:0] io_readyQInterface_2_bits,
  input         io_readyQInterface_3_ready,
  output        io_readyQInterface_3_valid,
  output [31:0] io_readyQInterface_3_bits
);
  wire  Queue_clock;
  wire  Queue_reset;
  wire  Queue_io_enq_ready;
  wire  Queue_io_enq_valid;
  wire [31:0] Queue_io_enq_bits;
  wire  Queue_io_deq_ready;
  wire  Queue_io_deq_valid;
  wire [31:0] Queue_io_deq_bits;
  wire  Queue_1_clock;
  wire  Queue_1_reset;
  wire  Queue_1_io_enq_ready;
  wire  Queue_1_io_enq_valid;
  wire [31:0] Queue_1_io_enq_bits;
  wire  Queue_1_io_deq_ready;
  wire  Queue_1_io_deq_valid;
  wire [31:0] Queue_1_io_deq_bits;
  wire  Queue_2_clock;
  wire  Queue_2_reset;
  wire  Queue_2_io_enq_ready;
  wire  Queue_2_io_enq_valid;
  wire [31:0] Queue_2_io_enq_bits;
  wire  Queue_2_io_deq_ready;
  wire  Queue_2_io_deq_valid;
  wire [31:0] Queue_2_io_deq_bits;
  wire  Queue_3_clock;
  wire  Queue_3_reset;
  wire  Queue_3_io_enq_ready;
  wire  Queue_3_io_enq_valid;
  wire [31:0] Queue_3_io_enq_bits;
  wire  Queue_3_io_deq_ready;
  wire  Queue_3_io_deq_valid;
  wire [31:0] Queue_3_io_deq_bits;
  wire  subQueues_0_enq_ready;
  wire  subQueues_1_enq_ready;
  wire  subQueues_2_enq_ready;
  wire  subQueues_3_enq_ready;
  wire  Queue_4_clock;
  wire  Queue_4_reset;
  wire  Queue_4_io_enq_ready;
  wire  Queue_4_io_enq_valid;
  wire [31:0] Queue_4_io_enq_bits;
  wire  Queue_4_io_deq_ready;
  wire  Queue_4_io_deq_valid;
  wire [31:0] Queue_4_io_deq_bits;
  wire  Queue_5_clock;
  wire  Queue_5_reset;
  wire  Queue_5_io_enq_ready;
  wire  Queue_5_io_enq_valid;
  wire [31:0] Queue_5_io_enq_bits;
  wire  Queue_5_io_deq_ready;
  wire  Queue_5_io_deq_valid;
  wire [31:0] Queue_5_io_deq_bits;
  wire  Queue_6_clock;
  wire  Queue_6_reset;
  wire  Queue_6_io_enq_ready;
  wire  Queue_6_io_enq_valid;
  wire [31:0] Queue_6_io_enq_bits;
  wire  Queue_6_io_deq_ready;
  wire  Queue_6_io_deq_valid;
  wire [31:0] Queue_6_io_deq_bits;
  wire  Queue_7_clock;
  wire  Queue_7_reset;
  wire  Queue_7_io_enq_ready;
  wire  Queue_7_io_enq_valid;
  wire [31:0] Queue_7_io_enq_bits;
  wire  Queue_7_io_deq_ready;
  wire  Queue_7_io_deq_valid;
  wire [31:0] Queue_7_io_deq_bits;
  wire  readyQueues_0_deq_valid;
  wire [31:0] readyQueues_0_deq_bits;
  wire  readyQueues_1_deq_valid;
  wire [31:0] readyQueues_1_deq_bits;
  wire  readyQueues_2_deq_valid;
  wire [31:0] readyQueues_2_deq_bits;
  wire  readyQueues_3_deq_valid;
  wire [31:0] readyQueues_3_deq_bits;
  Queue Queue (
    .clock(Queue_clock),
    .reset(Queue_reset),
    .io_enq_ready(Queue_io_enq_ready),
    .io_enq_valid(Queue_io_enq_valid),
    .io_enq_bits(Queue_io_enq_bits),
    .io_deq_ready(Queue_io_deq_ready),
    .io_deq_valid(Queue_io_deq_valid),
    .io_deq_bits(Queue_io_deq_bits)
  );
  Queue Queue_1 (
    .clock(Queue_1_clock),
    .reset(Queue_1_reset),
    .io_enq_ready(Queue_1_io_enq_ready),
    .io_enq_valid(Queue_1_io_enq_valid),
    .io_enq_bits(Queue_1_io_enq_bits),
    .io_deq_ready(Queue_1_io_deq_ready),
    .io_deq_valid(Queue_1_io_deq_valid),
    .io_deq_bits(Queue_1_io_deq_bits)
  );
  Queue Queue_2 (
    .clock(Queue_2_clock),
    .reset(Queue_2_reset),
    .io_enq_ready(Queue_2_io_enq_ready),
    .io_enq_valid(Queue_2_io_enq_valid),
    .io_enq_bits(Queue_2_io_enq_bits),
    .io_deq_ready(Queue_2_io_deq_ready),
    .io_deq_valid(Queue_2_io_deq_valid),
    .io_deq_bits(Queue_2_io_deq_bits)
  );
  Queue Queue_3 (
    .clock(Queue_3_clock),
    .reset(Queue_3_reset),
    .io_enq_ready(Queue_3_io_enq_ready),
    .io_enq_valid(Queue_3_io_enq_valid),
    .io_enq_bits(Queue_3_io_enq_bits),
    .io_deq_ready(Queue_3_io_deq_ready),
    .io_deq_valid(Queue_3_io_deq_valid),
    .io_deq_bits(Queue_3_io_deq_bits)
  );
  Queue Queue_4 (
    .clock(Queue_4_clock),
    .reset(Queue_4_reset),
    .io_enq_ready(Queue_4_io_enq_ready),
    .io_enq_valid(Queue_4_io_enq_valid),
    .io_enq_bits(Queue_4_io_enq_bits),
    .io_deq_ready(Queue_4_io_deq_ready),
    .io_deq_valid(Queue_4_io_deq_valid),
    .io_deq_bits(Queue_4_io_deq_bits)
  );
  Queue Queue_5 (
    .clock(Queue_5_clock),
    .reset(Queue_5_reset),
    .io_enq_ready(Queue_5_io_enq_ready),
    .io_enq_valid(Queue_5_io_enq_valid),
    .io_enq_bits(Queue_5_io_enq_bits),
    .io_deq_ready(Queue_5_io_deq_ready),
    .io_deq_valid(Queue_5_io_deq_valid),
    .io_deq_bits(Queue_5_io_deq_bits)
  );
  Queue Queue_6 (
    .clock(Queue_6_clock),
    .reset(Queue_6_reset),
    .io_enq_ready(Queue_6_io_enq_ready),
    .io_enq_valid(Queue_6_io_enq_valid),
    .io_enq_bits(Queue_6_io_enq_bits),
    .io_deq_ready(Queue_6_io_deq_ready),
    .io_deq_valid(Queue_6_io_deq_valid),
    .io_deq_bits(Queue_6_io_deq_bits)
  );
  Queue Queue_7 (
    .clock(Queue_7_clock),
    .reset(Queue_7_reset),
    .io_enq_ready(Queue_7_io_enq_ready),
    .io_enq_valid(Queue_7_io_enq_valid),
    .io_enq_bits(Queue_7_io_enq_bits),
    .io_deq_ready(Queue_7_io_deq_ready),
    .io_deq_valid(Queue_7_io_deq_valid),
    .io_deq_bits(Queue_7_io_deq_bits)
  );
  assign io_subQInterface_0_ready = subQueues_0_enq_ready;
  assign io_subQInterface_1_ready = subQueues_1_enq_ready;
  assign io_subQInterface_2_ready = subQueues_2_enq_ready;
  assign io_subQInterface_3_ready = subQueues_3_enq_ready;
  assign io_readyQInterface_0_valid = readyQueues_0_deq_valid;
  assign io_readyQInterface_0_bits = readyQueues_0_deq_bits;
  assign io_readyQInterface_1_valid = readyQueues_1_deq_valid;
  assign io_readyQInterface_1_bits = readyQueues_1_deq_bits;
  assign io_readyQInterface_2_valid = readyQueues_2_deq_valid;
  assign io_readyQInterface_2_bits = readyQueues_2_deq_bits;
  assign io_readyQInterface_3_valid = readyQueues_3_deq_valid;
  assign io_readyQInterface_3_bits = readyQueues_3_deq_bits;
  assign Queue_clock = clock;
  assign Queue_reset = reset;
  assign Queue_io_enq_valid = io_subQInterface_0_valid;
  assign Queue_io_enq_bits = io_subQInterface_0_bits;
  assign Queue_io_deq_ready = 1'h0;
  assign Queue_1_clock = clock;
  assign Queue_1_reset = reset;
  assign Queue_1_io_enq_valid = io_subQInterface_1_valid;
  assign Queue_1_io_enq_bits = io_subQInterface_1_bits;
  assign Queue_1_io_deq_ready = 1'h0;
  assign Queue_2_clock = clock;
  assign Queue_2_reset = reset;
  assign Queue_2_io_enq_valid = io_subQInterface_2_valid;
  assign Queue_2_io_enq_bits = io_subQInterface_2_bits;
  assign Queue_2_io_deq_ready = 1'h0;
  assign Queue_3_clock = clock;
  assign Queue_3_reset = reset;
  assign Queue_3_io_enq_valid = io_subQInterface_3_valid;
  assign Queue_3_io_enq_bits = io_subQInterface_3_bits;
  assign Queue_3_io_deq_ready = 1'h0;
  assign subQueues_0_enq_ready = Queue_io_enq_ready;
  assign subQueues_1_enq_ready = Queue_1_io_enq_ready;
  assign subQueues_2_enq_ready = Queue_2_io_enq_ready;
  assign subQueues_3_enq_ready = Queue_3_io_enq_ready;
  assign Queue_4_clock = clock;
  assign Queue_4_reset = reset;
  assign Queue_4_io_enq_valid = 1'h0;
  assign Queue_4_io_enq_bits = 32'h0;
  assign Queue_4_io_deq_ready = io_readyQInterface_0_ready;
  assign Queue_5_clock = clock;
  assign Queue_5_reset = reset;
  assign Queue_5_io_enq_valid = 1'h0;
  assign Queue_5_io_enq_bits = 32'h0;
  assign Queue_5_io_deq_ready = io_readyQInterface_1_ready;
  assign Queue_6_clock = clock;
  assign Queue_6_reset = reset;
  assign Queue_6_io_enq_valid = 1'h0;
  assign Queue_6_io_enq_bits = 32'h0;
  assign Queue_6_io_deq_ready = io_readyQInterface_2_ready;
  assign Queue_7_clock = clock;
  assign Queue_7_reset = reset;
  assign Queue_7_io_enq_valid = 1'h0;
  assign Queue_7_io_enq_bits = 32'h0;
  assign Queue_7_io_deq_ready = io_readyQInterface_3_ready;
  assign readyQueues_0_deq_valid = Queue_4_io_deq_valid;
  assign readyQueues_0_deq_bits = Queue_4_io_deq_bits;
  assign readyQueues_1_deq_valid = Queue_5_io_deq_valid;
  assign readyQueues_1_deq_bits = Queue_5_io_deq_bits;
  assign readyQueues_2_deq_valid = Queue_6_io_deq_valid;
  assign readyQueues_2_deq_bits = Queue_6_io_deq_bits;
  assign readyQueues_3_deq_valid = Queue_7_io_deq_valid;
  assign readyQueues_3_deq_bits = Queue_7_io_deq_bits;
endmodule
