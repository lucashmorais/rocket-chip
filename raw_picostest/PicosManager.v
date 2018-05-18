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
module Queue_1(
  input        clock,
  input        reset,
  output       io_enq_ready,
  input        io_enq_valid,
  input  [3:0] io_enq_bits,
  input        io_deq_ready,
  output       io_deq_valid,
  output [3:0] io_deq_bits
);
  reg [3:0] ram [0:1];
  reg [31:0] _RAND_0;
  wire [3:0] ram__T_43_data;
  wire  ram__T_43_addr;
  wire [3:0] ram__T_29_data;
  wire  ram__T_29_addr;
  wire  ram__T_29_mask;
  wire  ram__T_29_en;
  reg  value;
  reg [31:0] _RAND_1;
  reg  value_1;
  reg [31:0] _RAND_2;
  reg  maybe_full;
  reg [31:0] _RAND_3;
  wire  _T_20;
  wire  _T_22;
  wire  _T_23;
  wire  _T_24;
  wire  _T_25;
  wire  _T_27;
  wire [1:0] _T_32;
  wire  _T_33;
  wire  _GEN_4;
  wire [1:0] _T_36;
  wire  _T_37;
  wire  _GEN_5;
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
  assign _T_32 = value + 1'h1;
  assign _T_33 = _T_32[0:0];
  assign _GEN_4 = _T_25 ? _T_33 : value;
  assign _T_36 = value_1 + 1'h1;
  assign _T_37 = _T_36[0:0];
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
  for (initvar = 0; initvar < 2; initvar = initvar+1)
    ram[initvar] = _RAND_0[3:0];
  `endif // RANDOMIZE_MEM_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {1{$random}};
  value = _RAND_1[0:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_2 = {1{$random}};
  value_1 = _RAND_2[0:0];
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
      value <= 1'h0;
    end else begin
      if (_T_25) begin
        value <= _T_33;
      end
    end
    if (reset) begin
      value_1 <= 1'h0;
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
module RRArbiter(
  input         clock,
  output        io_in_0_ready,
  input         io_in_0_valid,
  input  [31:0] io_in_0_bits,
  output        io_in_1_ready,
  input         io_in_1_valid,
  input  [31:0] io_in_1_bits,
  output        io_in_2_ready,
  input         io_in_2_valid,
  input  [31:0] io_in_2_bits,
  output        io_in_3_ready,
  input         io_in_3_valid,
  input  [31:0] io_in_3_bits,
  input         io_in_4_valid,
  input  [31:0] io_in_4_bits,
  input         io_in_5_valid,
  input  [31:0] io_in_5_bits,
  input         io_in_6_valid,
  input  [31:0] io_in_6_bits,
  input         io_in_7_valid,
  input  [31:0] io_in_7_bits,
  input         io_in_8_valid,
  input  [31:0] io_in_8_bits,
  input         io_in_9_valid,
  input  [31:0] io_in_9_bits,
  input         io_in_10_valid,
  input  [31:0] io_in_10_bits,
  input         io_in_11_valid,
  input  [31:0] io_in_11_bits,
  input         io_in_12_valid,
  input  [31:0] io_in_12_bits,
  input         io_in_13_valid,
  input  [31:0] io_in_13_bits,
  input         io_in_14_valid,
  input  [31:0] io_in_14_bits,
  input         io_in_15_valid,
  input  [31:0] io_in_15_bits,
  input         io_out_ready,
  output        io_out_valid,
  output [31:0] io_out_bits,
  output [3:0]  io_chosen
);
  wire  _GEN_3;
  wire [31:0] _GEN_4;
  wire  _GEN_6;
  wire [31:0] _GEN_7;
  wire  _GEN_9;
  wire [31:0] _GEN_10;
  wire  _GEN_12;
  wire [31:0] _GEN_13;
  wire  _GEN_15;
  wire [31:0] _GEN_16;
  wire  _GEN_18;
  wire [31:0] _GEN_19;
  wire  _GEN_21;
  wire [31:0] _GEN_22;
  wire  _GEN_24;
  wire [31:0] _GEN_25;
  wire  _GEN_27;
  wire [31:0] _GEN_28;
  wire  _GEN_30;
  wire [31:0] _GEN_31;
  wire  _GEN_33;
  wire [31:0] _GEN_34;
  wire  _GEN_36;
  wire [31:0] _GEN_37;
  wire  _GEN_39;
  wire [31:0] _GEN_40;
  wire  _GEN_42;
  wire [31:0] _GEN_43;
  wire  _GEN_45;
  wire [31:0] _GEN_46;
  wire  _T_200;
  reg [3:0] lastGrant;
  reg [31:0] _RAND_0;
  wire [3:0] _GEN_47;
  wire  grantMask_1;
  wire  grantMask_2;
  wire  grantMask_3;
  wire  grantMask_4;
  wire  grantMask_5;
  wire  grantMask_6;
  wire  grantMask_7;
  wire  grantMask_8;
  wire  grantMask_9;
  wire  grantMask_10;
  wire  grantMask_11;
  wire  grantMask_12;
  wire  grantMask_13;
  wire  grantMask_14;
  wire  grantMask_15;
  wire  validMask_1;
  wire  validMask_2;
  wire  validMask_3;
  wire  validMask_4;
  wire  validMask_5;
  wire  validMask_6;
  wire  validMask_7;
  wire  validMask_8;
  wire  validMask_9;
  wire  validMask_10;
  wire  validMask_11;
  wire  validMask_12;
  wire  validMask_13;
  wire  validMask_14;
  wire  validMask_15;
  wire  _T_219;
  wire  _T_220;
  wire  _T_221;
  wire  _T_222;
  wire  _T_223;
  wire  _T_224;
  wire  _T_225;
  wire  _T_226;
  wire  _T_227;
  wire  _T_228;
  wire  _T_229;
  wire  _T_230;
  wire  _T_231;
  wire  _T_232;
  wire  _T_233;
  wire  _T_234;
  wire  _T_235;
  wire  _T_251;
  wire  _T_253;
  wire  _T_279;
  wire  _T_281;
  wire  _T_283;
  wire  _T_285;
  wire  _T_313;
  wire  _T_314;
  wire  _T_315;
  wire  _T_316;
  wire  _T_317;
  wire  _T_342;
  wire  _T_343;
  wire  _T_344;
  wire  _T_345;
  wire [3:0] _GEN_48;
  wire [3:0] _GEN_49;
  wire [3:0] _GEN_50;
  wire [3:0] _GEN_51;
  wire [3:0] _GEN_52;
  wire [3:0] _GEN_53;
  wire [3:0] _GEN_54;
  wire [3:0] _GEN_55;
  wire [3:0] _GEN_56;
  wire [3:0] _GEN_57;
  wire [3:0] _GEN_58;
  wire [3:0] _GEN_59;
  wire [3:0] _GEN_60;
  wire [3:0] _GEN_61;
  wire [3:0] _GEN_62;
  wire [3:0] _GEN_63;
  wire [3:0] _GEN_64;
  wire [3:0] _GEN_65;
  wire [3:0] _GEN_66;
  wire [3:0] _GEN_67;
  wire [3:0] _GEN_68;
  wire [3:0] _GEN_69;
  wire [3:0] _GEN_70;
  wire [3:0] _GEN_71;
  wire [3:0] _GEN_72;
  wire [3:0] _GEN_73;
  wire [3:0] _GEN_74;
  wire [3:0] _GEN_75;
  wire [3:0] _GEN_76;
  wire [3:0] _GEN_77;
  assign io_in_0_ready = _T_342;
  assign io_in_1_ready = _T_343;
  assign io_in_2_ready = _T_344;
  assign io_in_3_ready = _T_345;
  assign io_out_valid = _GEN_45;
  assign io_out_bits = _GEN_46;
  assign io_chosen = _GEN_77;
  assign _GEN_3 = 4'h1 == io_chosen ? io_in_1_valid : io_in_0_valid;
  assign _GEN_4 = 4'h1 == io_chosen ? io_in_1_bits : io_in_0_bits;
  assign _GEN_6 = 4'h2 == io_chosen ? io_in_2_valid : _GEN_3;
  assign _GEN_7 = 4'h2 == io_chosen ? io_in_2_bits : _GEN_4;
  assign _GEN_9 = 4'h3 == io_chosen ? io_in_3_valid : _GEN_6;
  assign _GEN_10 = 4'h3 == io_chosen ? io_in_3_bits : _GEN_7;
  assign _GEN_12 = 4'h4 == io_chosen ? io_in_4_valid : _GEN_9;
  assign _GEN_13 = 4'h4 == io_chosen ? io_in_4_bits : _GEN_10;
  assign _GEN_15 = 4'h5 == io_chosen ? io_in_5_valid : _GEN_12;
  assign _GEN_16 = 4'h5 == io_chosen ? io_in_5_bits : _GEN_13;
  assign _GEN_18 = 4'h6 == io_chosen ? io_in_6_valid : _GEN_15;
  assign _GEN_19 = 4'h6 == io_chosen ? io_in_6_bits : _GEN_16;
  assign _GEN_21 = 4'h7 == io_chosen ? io_in_7_valid : _GEN_18;
  assign _GEN_22 = 4'h7 == io_chosen ? io_in_7_bits : _GEN_19;
  assign _GEN_24 = 4'h8 == io_chosen ? io_in_8_valid : _GEN_21;
  assign _GEN_25 = 4'h8 == io_chosen ? io_in_8_bits : _GEN_22;
  assign _GEN_27 = 4'h9 == io_chosen ? io_in_9_valid : _GEN_24;
  assign _GEN_28 = 4'h9 == io_chosen ? io_in_9_bits : _GEN_25;
  assign _GEN_30 = 4'ha == io_chosen ? io_in_10_valid : _GEN_27;
  assign _GEN_31 = 4'ha == io_chosen ? io_in_10_bits : _GEN_28;
  assign _GEN_33 = 4'hb == io_chosen ? io_in_11_valid : _GEN_30;
  assign _GEN_34 = 4'hb == io_chosen ? io_in_11_bits : _GEN_31;
  assign _GEN_36 = 4'hc == io_chosen ? io_in_12_valid : _GEN_33;
  assign _GEN_37 = 4'hc == io_chosen ? io_in_12_bits : _GEN_34;
  assign _GEN_39 = 4'hd == io_chosen ? io_in_13_valid : _GEN_36;
  assign _GEN_40 = 4'hd == io_chosen ? io_in_13_bits : _GEN_37;
  assign _GEN_42 = 4'he == io_chosen ? io_in_14_valid : _GEN_39;
  assign _GEN_43 = 4'he == io_chosen ? io_in_14_bits : _GEN_40;
  assign _GEN_45 = 4'hf == io_chosen ? io_in_15_valid : _GEN_42;
  assign _GEN_46 = 4'hf == io_chosen ? io_in_15_bits : _GEN_43;
  assign _T_200 = io_out_ready & io_out_valid;
  assign _GEN_47 = _T_200 ? io_chosen : lastGrant;
  assign grantMask_1 = 4'h1 > lastGrant;
  assign grantMask_2 = 4'h2 > lastGrant;
  assign grantMask_3 = 4'h3 > lastGrant;
  assign grantMask_4 = 4'h4 > lastGrant;
  assign grantMask_5 = 4'h5 > lastGrant;
  assign grantMask_6 = 4'h6 > lastGrant;
  assign grantMask_7 = 4'h7 > lastGrant;
  assign grantMask_8 = 4'h8 > lastGrant;
  assign grantMask_9 = 4'h9 > lastGrant;
  assign grantMask_10 = 4'ha > lastGrant;
  assign grantMask_11 = 4'hb > lastGrant;
  assign grantMask_12 = 4'hc > lastGrant;
  assign grantMask_13 = 4'hd > lastGrant;
  assign grantMask_14 = 4'he > lastGrant;
  assign grantMask_15 = 4'hf > lastGrant;
  assign validMask_1 = io_in_1_valid & grantMask_1;
  assign validMask_2 = io_in_2_valid & grantMask_2;
  assign validMask_3 = io_in_3_valid & grantMask_3;
  assign validMask_4 = io_in_4_valid & grantMask_4;
  assign validMask_5 = io_in_5_valid & grantMask_5;
  assign validMask_6 = io_in_6_valid & grantMask_6;
  assign validMask_7 = io_in_7_valid & grantMask_7;
  assign validMask_8 = io_in_8_valid & grantMask_8;
  assign validMask_9 = io_in_9_valid & grantMask_9;
  assign validMask_10 = io_in_10_valid & grantMask_10;
  assign validMask_11 = io_in_11_valid & grantMask_11;
  assign validMask_12 = io_in_12_valid & grantMask_12;
  assign validMask_13 = io_in_13_valid & grantMask_13;
  assign validMask_14 = io_in_14_valid & grantMask_14;
  assign validMask_15 = io_in_15_valid & grantMask_15;
  assign _T_219 = validMask_1 | validMask_2;
  assign _T_220 = _T_219 | validMask_3;
  assign _T_221 = _T_220 | validMask_4;
  assign _T_222 = _T_221 | validMask_5;
  assign _T_223 = _T_222 | validMask_6;
  assign _T_224 = _T_223 | validMask_7;
  assign _T_225 = _T_224 | validMask_8;
  assign _T_226 = _T_225 | validMask_9;
  assign _T_227 = _T_226 | validMask_10;
  assign _T_228 = _T_227 | validMask_11;
  assign _T_229 = _T_228 | validMask_12;
  assign _T_230 = _T_229 | validMask_13;
  assign _T_231 = _T_230 | validMask_14;
  assign _T_232 = _T_231 | validMask_15;
  assign _T_233 = _T_232 | io_in_0_valid;
  assign _T_234 = _T_233 | io_in_1_valid;
  assign _T_235 = _T_234 | io_in_2_valid;
  assign _T_251 = validMask_1 == 1'h0;
  assign _T_253 = _T_219 == 1'h0;
  assign _T_279 = _T_232 == 1'h0;
  assign _T_281 = _T_233 == 1'h0;
  assign _T_283 = _T_234 == 1'h0;
  assign _T_285 = _T_235 == 1'h0;
  assign _T_313 = grantMask_1 | _T_281;
  assign _T_314 = _T_251 & grantMask_2;
  assign _T_315 = _T_314 | _T_283;
  assign _T_316 = _T_253 & grantMask_3;
  assign _T_317 = _T_316 | _T_285;
  assign _T_342 = _T_279 & io_out_ready;
  assign _T_343 = _T_313 & io_out_ready;
  assign _T_344 = _T_315 & io_out_ready;
  assign _T_345 = _T_317 & io_out_ready;
  assign _GEN_48 = io_in_14_valid ? 4'he : 4'hf;
  assign _GEN_49 = io_in_13_valid ? 4'hd : _GEN_48;
  assign _GEN_50 = io_in_12_valid ? 4'hc : _GEN_49;
  assign _GEN_51 = io_in_11_valid ? 4'hb : _GEN_50;
  assign _GEN_52 = io_in_10_valid ? 4'ha : _GEN_51;
  assign _GEN_53 = io_in_9_valid ? 4'h9 : _GEN_52;
  assign _GEN_54 = io_in_8_valid ? 4'h8 : _GEN_53;
  assign _GEN_55 = io_in_7_valid ? 4'h7 : _GEN_54;
  assign _GEN_56 = io_in_6_valid ? 4'h6 : _GEN_55;
  assign _GEN_57 = io_in_5_valid ? 4'h5 : _GEN_56;
  assign _GEN_58 = io_in_4_valid ? 4'h4 : _GEN_57;
  assign _GEN_59 = io_in_3_valid ? 4'h3 : _GEN_58;
  assign _GEN_60 = io_in_2_valid ? 4'h2 : _GEN_59;
  assign _GEN_61 = io_in_1_valid ? 4'h1 : _GEN_60;
  assign _GEN_62 = io_in_0_valid ? 4'h0 : _GEN_61;
  assign _GEN_63 = validMask_15 ? 4'hf : _GEN_62;
  assign _GEN_64 = validMask_14 ? 4'he : _GEN_63;
  assign _GEN_65 = validMask_13 ? 4'hd : _GEN_64;
  assign _GEN_66 = validMask_12 ? 4'hc : _GEN_65;
  assign _GEN_67 = validMask_11 ? 4'hb : _GEN_66;
  assign _GEN_68 = validMask_10 ? 4'ha : _GEN_67;
  assign _GEN_69 = validMask_9 ? 4'h9 : _GEN_68;
  assign _GEN_70 = validMask_8 ? 4'h8 : _GEN_69;
  assign _GEN_71 = validMask_7 ? 4'h7 : _GEN_70;
  assign _GEN_72 = validMask_6 ? 4'h6 : _GEN_71;
  assign _GEN_73 = validMask_5 ? 4'h5 : _GEN_72;
  assign _GEN_74 = validMask_4 ? 4'h4 : _GEN_73;
  assign _GEN_75 = validMask_3 ? 4'h3 : _GEN_74;
  assign _GEN_76 = validMask_2 ? 4'h2 : _GEN_75;
  assign _GEN_77 = validMask_1 ? 4'h1 : _GEN_76;
`ifdef RANDOMIZE
  integer initvar;
  initial begin
    `ifndef verilator
      #0.002 begin end
    `endif
  `ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{$random}};
  lastGrant = _RAND_0[3:0];
  `endif // RANDOMIZE_REG_INIT
  end
`endif // RANDOMIZE
  always @(posedge clock) begin
    if (_T_200) begin
      lastGrant <= io_chosen;
    end
  end
endmodule
module InOrderArbiter(
  input         clock,
  input         reset,
  output        io_in_req_0_ready,
  input         io_in_req_0_valid,
  input  [31:0] io_in_req_0_bits,
  output        io_in_req_1_ready,
  input         io_in_req_1_valid,
  input  [31:0] io_in_req_1_bits,
  output        io_in_req_2_ready,
  input         io_in_req_2_valid,
  input  [31:0] io_in_req_2_bits,
  output        io_in_req_3_ready,
  input         io_in_req_3_valid,
  input  [31:0] io_in_req_3_bits,
  input         io_in_req_4_valid,
  input  [31:0] io_in_req_4_bits,
  input         io_in_req_5_valid,
  input  [31:0] io_in_req_5_bits,
  input         io_in_req_6_valid,
  input  [31:0] io_in_req_6_bits,
  input         io_in_req_7_valid,
  input  [31:0] io_in_req_7_bits,
  input         io_in_req_8_valid,
  input  [31:0] io_in_req_8_bits,
  input         io_in_req_9_valid,
  input  [31:0] io_in_req_9_bits,
  input         io_in_req_10_valid,
  input  [31:0] io_in_req_10_bits,
  input         io_in_req_11_valid,
  input  [31:0] io_in_req_11_bits,
  input         io_in_req_12_valid,
  input  [31:0] io_in_req_12_bits,
  input         io_in_req_13_valid,
  input  [31:0] io_in_req_13_bits,
  input         io_in_req_14_valid,
  input  [31:0] io_in_req_14_bits,
  input         io_in_req_15_valid,
  input  [31:0] io_in_req_15_bits,
  input         io_in_resp_0_ready,
  output        io_in_resp_0_valid,
  output [31:0] io_in_resp_0_bits,
  input         io_in_resp_1_ready,
  output        io_in_resp_1_valid,
  output [31:0] io_in_resp_1_bits,
  input         io_in_resp_2_ready,
  output        io_in_resp_2_valid,
  output [31:0] io_in_resp_2_bits,
  input         io_in_resp_3_ready,
  output        io_in_resp_3_valid,
  output [31:0] io_in_resp_3_bits,
  input         io_in_resp_4_ready,
  input         io_in_resp_5_ready,
  input         io_in_resp_6_ready,
  input         io_in_resp_7_ready,
  input         io_in_resp_8_ready,
  input         io_in_resp_9_ready,
  input         io_in_resp_10_ready,
  input         io_in_resp_11_ready,
  input         io_in_resp_12_ready,
  input         io_in_resp_13_ready,
  input         io_in_resp_14_ready,
  input         io_in_resp_15_ready,
  input         io_out_req_ready,
  output        io_out_req_valid,
  output [31:0] io_out_req_bits,
  output        io_out_resp_ready,
  input         io_out_resp_valid,
  input  [31:0] io_out_resp_bits
);
  wire  Queue_clock;
  wire  Queue_reset;
  wire  Queue_io_enq_ready;
  wire  Queue_io_enq_valid;
  wire [3:0] Queue_io_enq_bits;
  wire  Queue_io_deq_ready;
  wire  Queue_io_deq_valid;
  wire [3:0] Queue_io_deq_bits;
  wire  RRArbiter_clock;
  wire  RRArbiter_io_in_0_ready;
  wire  RRArbiter_io_in_0_valid;
  wire [31:0] RRArbiter_io_in_0_bits;
  wire  RRArbiter_io_in_1_ready;
  wire  RRArbiter_io_in_1_valid;
  wire [31:0] RRArbiter_io_in_1_bits;
  wire  RRArbiter_io_in_2_ready;
  wire  RRArbiter_io_in_2_valid;
  wire [31:0] RRArbiter_io_in_2_bits;
  wire  RRArbiter_io_in_3_ready;
  wire  RRArbiter_io_in_3_valid;
  wire [31:0] RRArbiter_io_in_3_bits;
  wire  RRArbiter_io_in_4_valid;
  wire [31:0] RRArbiter_io_in_4_bits;
  wire  RRArbiter_io_in_5_valid;
  wire [31:0] RRArbiter_io_in_5_bits;
  wire  RRArbiter_io_in_6_valid;
  wire [31:0] RRArbiter_io_in_6_bits;
  wire  RRArbiter_io_in_7_valid;
  wire [31:0] RRArbiter_io_in_7_bits;
  wire  RRArbiter_io_in_8_valid;
  wire [31:0] RRArbiter_io_in_8_bits;
  wire  RRArbiter_io_in_9_valid;
  wire [31:0] RRArbiter_io_in_9_bits;
  wire  RRArbiter_io_in_10_valid;
  wire [31:0] RRArbiter_io_in_10_bits;
  wire  RRArbiter_io_in_11_valid;
  wire [31:0] RRArbiter_io_in_11_bits;
  wire  RRArbiter_io_in_12_valid;
  wire [31:0] RRArbiter_io_in_12_bits;
  wire  RRArbiter_io_in_13_valid;
  wire [31:0] RRArbiter_io_in_13_bits;
  wire  RRArbiter_io_in_14_valid;
  wire [31:0] RRArbiter_io_in_14_bits;
  wire  RRArbiter_io_in_15_valid;
  wire [31:0] RRArbiter_io_in_15_bits;
  wire  RRArbiter_io_out_ready;
  wire  RRArbiter_io_out_valid;
  wire [31:0] RRArbiter_io_out_bits;
  wire [3:0] RRArbiter_io_chosen;
  wire  _T_246;
  wire  _T_247;
  wire  _T_248;
  wire  _T_252;
  wire  _T_254;
  wire  _T_255;
  wire  _T_257;
  wire  _T_258;
  wire  _T_260;
  wire  _T_261;
  wire  _T_263;
  wire  _T_264;
  wire  _GEN_2;
  wire  _GEN_5;
  wire  _GEN_8;
  wire  _GEN_11;
  wire  _GEN_14;
  wire  _GEN_17;
  wire  _GEN_20;
  wire  _GEN_23;
  wire  _GEN_26;
  wire  _GEN_29;
  wire  _GEN_32;
  wire  _GEN_35;
  wire  _GEN_38;
  wire  _GEN_41;
  wire  _GEN_44;
  wire  _T_301;
  wire  _T_302;
  Queue_1 Queue (
    .clock(Queue_clock),
    .reset(Queue_reset),
    .io_enq_ready(Queue_io_enq_ready),
    .io_enq_valid(Queue_io_enq_valid),
    .io_enq_bits(Queue_io_enq_bits),
    .io_deq_ready(Queue_io_deq_ready),
    .io_deq_valid(Queue_io_deq_valid),
    .io_deq_bits(Queue_io_deq_bits)
  );
  RRArbiter RRArbiter (
    .clock(RRArbiter_clock),
    .io_in_0_ready(RRArbiter_io_in_0_ready),
    .io_in_0_valid(RRArbiter_io_in_0_valid),
    .io_in_0_bits(RRArbiter_io_in_0_bits),
    .io_in_1_ready(RRArbiter_io_in_1_ready),
    .io_in_1_valid(RRArbiter_io_in_1_valid),
    .io_in_1_bits(RRArbiter_io_in_1_bits),
    .io_in_2_ready(RRArbiter_io_in_2_ready),
    .io_in_2_valid(RRArbiter_io_in_2_valid),
    .io_in_2_bits(RRArbiter_io_in_2_bits),
    .io_in_3_ready(RRArbiter_io_in_3_ready),
    .io_in_3_valid(RRArbiter_io_in_3_valid),
    .io_in_3_bits(RRArbiter_io_in_3_bits),
    .io_in_4_valid(RRArbiter_io_in_4_valid),
    .io_in_4_bits(RRArbiter_io_in_4_bits),
    .io_in_5_valid(RRArbiter_io_in_5_valid),
    .io_in_5_bits(RRArbiter_io_in_5_bits),
    .io_in_6_valid(RRArbiter_io_in_6_valid),
    .io_in_6_bits(RRArbiter_io_in_6_bits),
    .io_in_7_valid(RRArbiter_io_in_7_valid),
    .io_in_7_bits(RRArbiter_io_in_7_bits),
    .io_in_8_valid(RRArbiter_io_in_8_valid),
    .io_in_8_bits(RRArbiter_io_in_8_bits),
    .io_in_9_valid(RRArbiter_io_in_9_valid),
    .io_in_9_bits(RRArbiter_io_in_9_bits),
    .io_in_10_valid(RRArbiter_io_in_10_valid),
    .io_in_10_bits(RRArbiter_io_in_10_bits),
    .io_in_11_valid(RRArbiter_io_in_11_valid),
    .io_in_11_bits(RRArbiter_io_in_11_bits),
    .io_in_12_valid(RRArbiter_io_in_12_valid),
    .io_in_12_bits(RRArbiter_io_in_12_bits),
    .io_in_13_valid(RRArbiter_io_in_13_valid),
    .io_in_13_bits(RRArbiter_io_in_13_bits),
    .io_in_14_valid(RRArbiter_io_in_14_valid),
    .io_in_14_bits(RRArbiter_io_in_14_bits),
    .io_in_15_valid(RRArbiter_io_in_15_valid),
    .io_in_15_bits(RRArbiter_io_in_15_bits),
    .io_out_ready(RRArbiter_io_out_ready),
    .io_out_valid(RRArbiter_io_out_valid),
    .io_out_bits(RRArbiter_io_out_bits),
    .io_chosen(RRArbiter_io_chosen)
  );
  assign io_in_req_0_ready = RRArbiter_io_in_0_ready;
  assign io_in_req_1_ready = RRArbiter_io_in_1_ready;
  assign io_in_req_2_ready = RRArbiter_io_in_2_ready;
  assign io_in_req_3_ready = RRArbiter_io_in_3_ready;
  assign io_in_resp_0_valid = _T_255;
  assign io_in_resp_0_bits = io_out_resp_bits;
  assign io_in_resp_1_valid = _T_258;
  assign io_in_resp_1_bits = io_out_resp_bits;
  assign io_in_resp_2_valid = _T_261;
  assign io_in_resp_2_bits = io_out_resp_bits;
  assign io_in_resp_3_valid = _T_264;
  assign io_in_resp_3_bits = io_out_resp_bits;
  assign io_out_req_valid = _T_246;
  assign io_out_req_bits = RRArbiter_io_out_bits;
  assign io_out_resp_ready = _T_302;
  assign Queue_clock = clock;
  assign Queue_reset = reset;
  assign Queue_io_enq_valid = _T_247;
  assign Queue_io_enq_bits = RRArbiter_io_chosen;
  assign Queue_io_deq_ready = _T_301;
  assign RRArbiter_clock = clock;
  assign RRArbiter_io_in_0_valid = io_in_req_0_valid;
  assign RRArbiter_io_in_0_bits = io_in_req_0_bits;
  assign RRArbiter_io_in_1_valid = io_in_req_1_valid;
  assign RRArbiter_io_in_1_bits = io_in_req_1_bits;
  assign RRArbiter_io_in_2_valid = io_in_req_2_valid;
  assign RRArbiter_io_in_2_bits = io_in_req_2_bits;
  assign RRArbiter_io_in_3_valid = io_in_req_3_valid;
  assign RRArbiter_io_in_3_bits = io_in_req_3_bits;
  assign RRArbiter_io_in_4_valid = io_in_req_4_valid;
  assign RRArbiter_io_in_4_bits = io_in_req_4_bits;
  assign RRArbiter_io_in_5_valid = io_in_req_5_valid;
  assign RRArbiter_io_in_5_bits = io_in_req_5_bits;
  assign RRArbiter_io_in_6_valid = io_in_req_6_valid;
  assign RRArbiter_io_in_6_bits = io_in_req_6_bits;
  assign RRArbiter_io_in_7_valid = io_in_req_7_valid;
  assign RRArbiter_io_in_7_bits = io_in_req_7_bits;
  assign RRArbiter_io_in_8_valid = io_in_req_8_valid;
  assign RRArbiter_io_in_8_bits = io_in_req_8_bits;
  assign RRArbiter_io_in_9_valid = io_in_req_9_valid;
  assign RRArbiter_io_in_9_bits = io_in_req_9_bits;
  assign RRArbiter_io_in_10_valid = io_in_req_10_valid;
  assign RRArbiter_io_in_10_bits = io_in_req_10_bits;
  assign RRArbiter_io_in_11_valid = io_in_req_11_valid;
  assign RRArbiter_io_in_11_bits = io_in_req_11_bits;
  assign RRArbiter_io_in_12_valid = io_in_req_12_valid;
  assign RRArbiter_io_in_12_bits = io_in_req_12_bits;
  assign RRArbiter_io_in_13_valid = io_in_req_13_valid;
  assign RRArbiter_io_in_13_bits = io_in_req_13_bits;
  assign RRArbiter_io_in_14_valid = io_in_req_14_valid;
  assign RRArbiter_io_in_14_bits = io_in_req_14_bits;
  assign RRArbiter_io_in_15_valid = io_in_req_15_valid;
  assign RRArbiter_io_in_15_bits = io_in_req_15_bits;
  assign RRArbiter_io_out_ready = _T_248;
  assign _T_246 = RRArbiter_io_out_valid & Queue_io_enq_ready;
  assign _T_247 = RRArbiter_io_out_valid & io_out_req_ready;
  assign _T_248 = Queue_io_enq_ready & io_out_req_ready;
  assign _T_252 = Queue_io_deq_valid & io_out_resp_valid;
  assign _T_254 = Queue_io_deq_bits == 4'h0;
  assign _T_255 = _T_252 & _T_254;
  assign _T_257 = Queue_io_deq_bits == 4'h1;
  assign _T_258 = _T_252 & _T_257;
  assign _T_260 = Queue_io_deq_bits == 4'h2;
  assign _T_261 = _T_252 & _T_260;
  assign _T_263 = Queue_io_deq_bits == 4'h3;
  assign _T_264 = _T_252 & _T_263;
  assign _GEN_2 = 4'h1 == Queue_io_deq_bits ? io_in_resp_1_ready : io_in_resp_0_ready;
  assign _GEN_5 = 4'h2 == Queue_io_deq_bits ? io_in_resp_2_ready : _GEN_2;
  assign _GEN_8 = 4'h3 == Queue_io_deq_bits ? io_in_resp_3_ready : _GEN_5;
  assign _GEN_11 = 4'h4 == Queue_io_deq_bits ? io_in_resp_4_ready : _GEN_8;
  assign _GEN_14 = 4'h5 == Queue_io_deq_bits ? io_in_resp_5_ready : _GEN_11;
  assign _GEN_17 = 4'h6 == Queue_io_deq_bits ? io_in_resp_6_ready : _GEN_14;
  assign _GEN_20 = 4'h7 == Queue_io_deq_bits ? io_in_resp_7_ready : _GEN_17;
  assign _GEN_23 = 4'h8 == Queue_io_deq_bits ? io_in_resp_8_ready : _GEN_20;
  assign _GEN_26 = 4'h9 == Queue_io_deq_bits ? io_in_resp_9_ready : _GEN_23;
  assign _GEN_29 = 4'ha == Queue_io_deq_bits ? io_in_resp_10_ready : _GEN_26;
  assign _GEN_32 = 4'hb == Queue_io_deq_bits ? io_in_resp_11_ready : _GEN_29;
  assign _GEN_35 = 4'hc == Queue_io_deq_bits ? io_in_resp_12_ready : _GEN_32;
  assign _GEN_38 = 4'hd == Queue_io_deq_bits ? io_in_resp_13_ready : _GEN_35;
  assign _GEN_41 = 4'he == Queue_io_deq_bits ? io_in_resp_14_ready : _GEN_38;
  assign _GEN_44 = 4'hf == Queue_io_deq_bits ? io_in_resp_15_ready : _GEN_41;
  assign _T_301 = _GEN_44 & io_out_resp_valid;
  assign _T_302 = _GEN_44 & Queue_io_deq_valid;
endmodule
module PicosManager(
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
  wire  subQueue_clock;
  wire  subQueue_reset;
  wire  subQueue_io_enq_ready;
  wire  subQueue_io_enq_valid;
  wire [31:0] subQueue_io_enq_bits;
  wire  subQueue_io_deq_ready;
  wire  subQueue_io_deq_valid;
  wire [31:0] subQueue_io_deq_bits;
  wire  arbiter_clock;
  wire  arbiter_reset;
  wire  arbiter_io_in_req_0_ready;
  wire  arbiter_io_in_req_0_valid;
  wire [31:0] arbiter_io_in_req_0_bits;
  wire  arbiter_io_in_req_1_ready;
  wire  arbiter_io_in_req_1_valid;
  wire [31:0] arbiter_io_in_req_1_bits;
  wire  arbiter_io_in_req_2_ready;
  wire  arbiter_io_in_req_2_valid;
  wire [31:0] arbiter_io_in_req_2_bits;
  wire  arbiter_io_in_req_3_ready;
  wire  arbiter_io_in_req_3_valid;
  wire [31:0] arbiter_io_in_req_3_bits;
  wire  arbiter_io_in_req_4_valid;
  wire [31:0] arbiter_io_in_req_4_bits;
  wire  arbiter_io_in_req_5_valid;
  wire [31:0] arbiter_io_in_req_5_bits;
  wire  arbiter_io_in_req_6_valid;
  wire [31:0] arbiter_io_in_req_6_bits;
  wire  arbiter_io_in_req_7_valid;
  wire [31:0] arbiter_io_in_req_7_bits;
  wire  arbiter_io_in_req_8_valid;
  wire [31:0] arbiter_io_in_req_8_bits;
  wire  arbiter_io_in_req_9_valid;
  wire [31:0] arbiter_io_in_req_9_bits;
  wire  arbiter_io_in_req_10_valid;
  wire [31:0] arbiter_io_in_req_10_bits;
  wire  arbiter_io_in_req_11_valid;
  wire [31:0] arbiter_io_in_req_11_bits;
  wire  arbiter_io_in_req_12_valid;
  wire [31:0] arbiter_io_in_req_12_bits;
  wire  arbiter_io_in_req_13_valid;
  wire [31:0] arbiter_io_in_req_13_bits;
  wire  arbiter_io_in_req_14_valid;
  wire [31:0] arbiter_io_in_req_14_bits;
  wire  arbiter_io_in_req_15_valid;
  wire [31:0] arbiter_io_in_req_15_bits;
  wire  arbiter_io_in_resp_0_ready;
  wire  arbiter_io_in_resp_0_valid;
  wire [31:0] arbiter_io_in_resp_0_bits;
  wire  arbiter_io_in_resp_1_ready;
  wire  arbiter_io_in_resp_1_valid;
  wire [31:0] arbiter_io_in_resp_1_bits;
  wire  arbiter_io_in_resp_2_ready;
  wire  arbiter_io_in_resp_2_valid;
  wire [31:0] arbiter_io_in_resp_2_bits;
  wire  arbiter_io_in_resp_3_ready;
  wire  arbiter_io_in_resp_3_valid;
  wire [31:0] arbiter_io_in_resp_3_bits;
  wire  arbiter_io_in_resp_4_ready;
  wire  arbiter_io_in_resp_5_ready;
  wire  arbiter_io_in_resp_6_ready;
  wire  arbiter_io_in_resp_7_ready;
  wire  arbiter_io_in_resp_8_ready;
  wire  arbiter_io_in_resp_9_ready;
  wire  arbiter_io_in_resp_10_ready;
  wire  arbiter_io_in_resp_11_ready;
  wire  arbiter_io_in_resp_12_ready;
  wire  arbiter_io_in_resp_13_ready;
  wire  arbiter_io_in_resp_14_ready;
  wire  arbiter_io_in_resp_15_ready;
  wire  arbiter_io_out_req_ready;
  wire  arbiter_io_out_req_valid;
  wire [31:0] arbiter_io_out_req_bits;
  wire  arbiter_io_out_resp_ready;
  wire  arbiter_io_out_resp_valid;
  wire [31:0] arbiter_io_out_resp_bits;
  Queue subQueue (
    .clock(subQueue_clock),
    .reset(subQueue_reset),
    .io_enq_ready(subQueue_io_enq_ready),
    .io_enq_valid(subQueue_io_enq_valid),
    .io_enq_bits(subQueue_io_enq_bits),
    .io_deq_ready(subQueue_io_deq_ready),
    .io_deq_valid(subQueue_io_deq_valid),
    .io_deq_bits(subQueue_io_deq_bits)
  );
  InOrderArbiter arbiter (
    .clock(arbiter_clock),
    .reset(arbiter_reset),
    .io_in_req_0_ready(arbiter_io_in_req_0_ready),
    .io_in_req_0_valid(arbiter_io_in_req_0_valid),
    .io_in_req_0_bits(arbiter_io_in_req_0_bits),
    .io_in_req_1_ready(arbiter_io_in_req_1_ready),
    .io_in_req_1_valid(arbiter_io_in_req_1_valid),
    .io_in_req_1_bits(arbiter_io_in_req_1_bits),
    .io_in_req_2_ready(arbiter_io_in_req_2_ready),
    .io_in_req_2_valid(arbiter_io_in_req_2_valid),
    .io_in_req_2_bits(arbiter_io_in_req_2_bits),
    .io_in_req_3_ready(arbiter_io_in_req_3_ready),
    .io_in_req_3_valid(arbiter_io_in_req_3_valid),
    .io_in_req_3_bits(arbiter_io_in_req_3_bits),
    .io_in_req_4_valid(arbiter_io_in_req_4_valid),
    .io_in_req_4_bits(arbiter_io_in_req_4_bits),
    .io_in_req_5_valid(arbiter_io_in_req_5_valid),
    .io_in_req_5_bits(arbiter_io_in_req_5_bits),
    .io_in_req_6_valid(arbiter_io_in_req_6_valid),
    .io_in_req_6_bits(arbiter_io_in_req_6_bits),
    .io_in_req_7_valid(arbiter_io_in_req_7_valid),
    .io_in_req_7_bits(arbiter_io_in_req_7_bits),
    .io_in_req_8_valid(arbiter_io_in_req_8_valid),
    .io_in_req_8_bits(arbiter_io_in_req_8_bits),
    .io_in_req_9_valid(arbiter_io_in_req_9_valid),
    .io_in_req_9_bits(arbiter_io_in_req_9_bits),
    .io_in_req_10_valid(arbiter_io_in_req_10_valid),
    .io_in_req_10_bits(arbiter_io_in_req_10_bits),
    .io_in_req_11_valid(arbiter_io_in_req_11_valid),
    .io_in_req_11_bits(arbiter_io_in_req_11_bits),
    .io_in_req_12_valid(arbiter_io_in_req_12_valid),
    .io_in_req_12_bits(arbiter_io_in_req_12_bits),
    .io_in_req_13_valid(arbiter_io_in_req_13_valid),
    .io_in_req_13_bits(arbiter_io_in_req_13_bits),
    .io_in_req_14_valid(arbiter_io_in_req_14_valid),
    .io_in_req_14_bits(arbiter_io_in_req_14_bits),
    .io_in_req_15_valid(arbiter_io_in_req_15_valid),
    .io_in_req_15_bits(arbiter_io_in_req_15_bits),
    .io_in_resp_0_ready(arbiter_io_in_resp_0_ready),
    .io_in_resp_0_valid(arbiter_io_in_resp_0_valid),
    .io_in_resp_0_bits(arbiter_io_in_resp_0_bits),
    .io_in_resp_1_ready(arbiter_io_in_resp_1_ready),
    .io_in_resp_1_valid(arbiter_io_in_resp_1_valid),
    .io_in_resp_1_bits(arbiter_io_in_resp_1_bits),
    .io_in_resp_2_ready(arbiter_io_in_resp_2_ready),
    .io_in_resp_2_valid(arbiter_io_in_resp_2_valid),
    .io_in_resp_2_bits(arbiter_io_in_resp_2_bits),
    .io_in_resp_3_ready(arbiter_io_in_resp_3_ready),
    .io_in_resp_3_valid(arbiter_io_in_resp_3_valid),
    .io_in_resp_3_bits(arbiter_io_in_resp_3_bits),
    .io_in_resp_4_ready(arbiter_io_in_resp_4_ready),
    .io_in_resp_5_ready(arbiter_io_in_resp_5_ready),
    .io_in_resp_6_ready(arbiter_io_in_resp_6_ready),
    .io_in_resp_7_ready(arbiter_io_in_resp_7_ready),
    .io_in_resp_8_ready(arbiter_io_in_resp_8_ready),
    .io_in_resp_9_ready(arbiter_io_in_resp_9_ready),
    .io_in_resp_10_ready(arbiter_io_in_resp_10_ready),
    .io_in_resp_11_ready(arbiter_io_in_resp_11_ready),
    .io_in_resp_12_ready(arbiter_io_in_resp_12_ready),
    .io_in_resp_13_ready(arbiter_io_in_resp_13_ready),
    .io_in_resp_14_ready(arbiter_io_in_resp_14_ready),
    .io_in_resp_15_ready(arbiter_io_in_resp_15_ready),
    .io_out_req_ready(arbiter_io_out_req_ready),
    .io_out_req_valid(arbiter_io_out_req_valid),
    .io_out_req_bits(arbiter_io_out_req_bits),
    .io_out_resp_ready(arbiter_io_out_resp_ready),
    .io_out_resp_valid(arbiter_io_out_resp_valid),
    .io_out_resp_bits(arbiter_io_out_resp_bits)
  );
  assign io_subQInterface_0_ready = arbiter_io_in_req_0_ready;
  assign io_subQInterface_1_ready = arbiter_io_in_req_1_ready;
  assign io_subQInterface_2_ready = arbiter_io_in_req_2_ready;
  assign io_subQInterface_3_ready = arbiter_io_in_req_3_ready;
  assign io_readyQInterface_0_valid = arbiter_io_in_resp_0_valid;
  assign io_readyQInterface_0_bits = arbiter_io_in_resp_0_bits;
  assign io_readyQInterface_1_valid = arbiter_io_in_resp_1_valid;
  assign io_readyQInterface_1_bits = arbiter_io_in_resp_1_bits;
  assign io_readyQInterface_2_valid = arbiter_io_in_resp_2_valid;
  assign io_readyQInterface_2_bits = arbiter_io_in_resp_2_bits;
  assign io_readyQInterface_3_valid = arbiter_io_in_resp_3_valid;
  assign io_readyQInterface_3_bits = arbiter_io_in_resp_3_bits;
  assign subQueue_clock = clock;
  assign subQueue_reset = reset;
  assign subQueue_io_enq_valid = arbiter_io_out_req_valid;
  assign subQueue_io_enq_bits = arbiter_io_out_req_bits;
  assign subQueue_io_deq_ready = arbiter_io_out_resp_ready;
  assign arbiter_clock = clock;
  assign arbiter_reset = reset;
  assign arbiter_io_in_req_0_valid = io_subQInterface_0_valid;
  assign arbiter_io_in_req_0_bits = io_subQInterface_0_bits;
  assign arbiter_io_in_req_1_valid = io_subQInterface_1_valid;
  assign arbiter_io_in_req_1_bits = io_subQInterface_1_bits;
  assign arbiter_io_in_req_2_valid = io_subQInterface_2_valid;
  assign arbiter_io_in_req_2_bits = io_subQInterface_2_bits;
  assign arbiter_io_in_req_3_valid = io_subQInterface_3_valid;
  assign arbiter_io_in_req_3_bits = io_subQInterface_3_bits;
  assign arbiter_io_in_req_4_valid = 1'h0;
  assign arbiter_io_in_req_4_bits = 32'h0;
  assign arbiter_io_in_req_5_valid = 1'h0;
  assign arbiter_io_in_req_5_bits = 32'h0;
  assign arbiter_io_in_req_6_valid = 1'h0;
  assign arbiter_io_in_req_6_bits = 32'h0;
  assign arbiter_io_in_req_7_valid = 1'h0;
  assign arbiter_io_in_req_7_bits = 32'h0;
  assign arbiter_io_in_req_8_valid = 1'h0;
  assign arbiter_io_in_req_8_bits = 32'h0;
  assign arbiter_io_in_req_9_valid = 1'h0;
  assign arbiter_io_in_req_9_bits = 32'h0;
  assign arbiter_io_in_req_10_valid = 1'h0;
  assign arbiter_io_in_req_10_bits = 32'h0;
  assign arbiter_io_in_req_11_valid = 1'h0;
  assign arbiter_io_in_req_11_bits = 32'h0;
  assign arbiter_io_in_req_12_valid = 1'h0;
  assign arbiter_io_in_req_12_bits = 32'h0;
  assign arbiter_io_in_req_13_valid = 1'h0;
  assign arbiter_io_in_req_13_bits = 32'h0;
  assign arbiter_io_in_req_14_valid = 1'h0;
  assign arbiter_io_in_req_14_bits = 32'h0;
  assign arbiter_io_in_req_15_valid = 1'h0;
  assign arbiter_io_in_req_15_bits = 32'h0;
  assign arbiter_io_in_resp_0_ready = io_readyQInterface_0_ready;
  assign arbiter_io_in_resp_1_ready = io_readyQInterface_1_ready;
  assign arbiter_io_in_resp_2_ready = io_readyQInterface_2_ready;
  assign arbiter_io_in_resp_3_ready = io_readyQInterface_3_ready;
  assign arbiter_io_in_resp_4_ready = 1'h0;
  assign arbiter_io_in_resp_5_ready = 1'h0;
  assign arbiter_io_in_resp_6_ready = 1'h0;
  assign arbiter_io_in_resp_7_ready = 1'h0;
  assign arbiter_io_in_resp_8_ready = 1'h0;
  assign arbiter_io_in_resp_9_ready = 1'h0;
  assign arbiter_io_in_resp_10_ready = 1'h0;
  assign arbiter_io_in_resp_11_ready = 1'h0;
  assign arbiter_io_in_resp_12_ready = 1'h0;
  assign arbiter_io_in_resp_13_ready = 1'h0;
  assign arbiter_io_in_resp_14_ready = 1'h0;
  assign arbiter_io_in_resp_15_ready = 1'h0;
  assign arbiter_io_out_req_ready = subQueue_io_enq_ready;
  assign arbiter_io_out_resp_valid = subQueue_io_deq_valid;
  assign arbiter_io_out_resp_bits = subQueue_io_deq_bits;
endmodule
