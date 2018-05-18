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

module SimpleTimer(
  input   clock,
  input   reset,
  input   io_start,
  input   io_stop,
  output  io_timeout
);
  reg [10:0] countdown;
  reg [31:0] _RAND_0;
  reg  active;
  reg [31:0] _RAND_1;
  wire [11:0] _T_9;
  wire [11:0] _T_10;
  wire [10:0] _T_11;
  wire [10:0] _GEN_0;
  wire  _GEN_1;
  wire [10:0] _GEN_2;
  wire  _GEN_3;
  wire  _T_16;
  wire  _T_17;
  assign io_timeout = _T_17;
  assign _T_9 = countdown - 11'h1;
  assign _T_10 = $unsigned(_T_9);
  assign _T_11 = _T_10[10:0];
  assign _GEN_0 = active ? _T_11 : countdown;
  assign _GEN_1 = io_start ? 1'h1 : active;
  assign _GEN_2 = io_start ? 11'h4af : _GEN_0;
  assign _GEN_3 = io_stop ? 1'h0 : _GEN_1;
  assign _T_16 = countdown == 11'h0;
  assign _T_17 = _T_16 & active;
`ifdef RANDOMIZE
  integer initvar;
  initial begin
    `ifndef verilator
      #0.002 begin end
    `endif
  `ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{$random}};
  countdown = _RAND_0[10:0];
  `endif // RANDOMIZE_REG_INIT
  `ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {1{$random}};
  active = _RAND_1[0:0];
  `endif // RANDOMIZE_REG_INIT
  end
`endif // RANDOMIZE
  always @(posedge clock) begin
    if (io_start) begin
      countdown <= 11'h4af;
    end else begin
      if (active) begin
        countdown <= _T_11;
      end
    end
    if (reset) begin
      active <= 1'h0;
    end else begin
      if (io_stop) begin
        active <= 1'h0;
      end else begin
        if (io_start) begin
          active <= 1'h1;
        end
      end
    end
  end
endmodule
module PicosManagerTester(
  input   clock,
  input   reset,
  output  io_finished,
  input   io_start
);
  wire  _T_5;
  wire  SimpleTimer_clock;
  wire  SimpleTimer_reset;
  wire  SimpleTimer_io_start;
  wire  SimpleTimer_io_stop;
  wire  SimpleTimer_io_timeout;
  wire  _T_7;
  wire  _T_8;
  wire  _T_10;
  SimpleTimer SimpleTimer (
    .clock(SimpleTimer_clock),
    .reset(SimpleTimer_reset),
    .io_start(SimpleTimer_io_start),
    .io_stop(SimpleTimer_io_stop),
    .io_timeout(SimpleTimer_io_timeout)
  );
  assign io_finished = 1'h0;
  assign _T_5 = reset == 1'h0;
  assign SimpleTimer_clock = clock;
  assign SimpleTimer_reset = reset;
  assign SimpleTimer_io_start = io_start;
  assign SimpleTimer_io_stop = io_finished;
  assign _T_7 = SimpleTimer_io_timeout == 1'h0;
  assign _T_8 = _T_7 | reset;
  assign _T_10 = _T_8 == 1'h0;
  always @(posedge clock) begin
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_start & _T_5) begin
          $fwrite(32'h80000002,"Started UnitTest PicosManagerTester\n");
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_10) begin
          $fwrite(32'h80000002,"Assertion failed: UnitTest PicosManagerTester timed out\n    at UnitTest.scala:22 assert(!timed_out, s\"UnitTest $testName timed out\")\n");
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_10) begin
          $fatal;
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
  end
endmodule
