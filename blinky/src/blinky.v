//
`default_nettype none
//

module blinky(i_clk, o_led);
  input wire i_clk;
  output wire o_led;

  reg	[25:0]	counter;

  always @(posedge i_clk)
    counter <= counter + 1'b1;

  assign o_led = counter[25];

endmodule
