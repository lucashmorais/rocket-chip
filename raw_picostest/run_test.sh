#!/bin/bash

cp ../*.v .

# cleanup
rm -rf obj_dir
rm -f  PicosManager.vcd

# run Verilator to translate Verilog into C++, include C++ testbench
verilator --cc --trace -O3 -CFLAGS -O3 PicosManager.v --exe PicosManager_tb.cpp
#verilator --cc --trace PicosManager.v --exe PicosManager_tb.cpp

# build C++ project
make -j -C obj_dir/ -f VPicosManager.mk VPicosManager

# run executable simulation
obj_dir/VPicosManager

# view waveforms
#gtkwave PicosManager.vcd 2>&1 > /dev/null &
