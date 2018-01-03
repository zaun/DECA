//
`default_nettype none
//

module fifo #(
  parameter DATA_LEN = 8,
  parameter FIFO_LEN = 16  // must be a power of 2. (2, 4, 8, 16, 32)
) (
  input wire i_reset,
  input wire i_clk_write,
  input wire i_write,
  input wire [(DATA_LEN - 1):0] i_data,
  input wire i_clk_read,
  input wire i_read,
  output wire o_empty_n,
  output wire o_write_error,
  output wire o_read_error,
  // output wire [($clog2(FIFO_LEN) - 1):0] o_full_count,
  // output wire [($clog2(FIFO_LEN) - 1):0] o_free_count,
  output wire [(DATA_LEN - 1):0] o_data
);

  reg	[($clog2(FIFO_LEN) - 1):0] addr_read, addr_write, addr_next;
  reg	[(DATA_LEN - 1):0] mem	[0:(FIFO_LEN - 1)];
  reg full, empty, read_error, write_error;
  reg [(DATA_LEN - 1):0] data;
  // reg [($clog2(FIFO_LEN) - 1):0] full_count, free_count;

  initial begin
    addr_next = addr_write + 1'b1;
    full = (addr_next == addr_read);
    empty = (addr_write == addr_read);
    data = 0;
  end

  always @(posedge i_clk_read) begin
    if (i_reset) begin
      addr_read <= 0;
      data <= 0;
      read_error <= 0;
    end if (i_read && !empty && !i_reset) begin
      data <= mem[addr_read];
      read_error <= 0;
      addr_read <= addr_read + 1'b1;
    end else if (i_read && empty && !i_reset) begin
      read_error <= 1;
      data <= 0;
    end else begin
      read_error <= 0;
    end
  end

  always @(posedge i_clk_write) begin
    if (i_reset) begin
      addr_write <= 0;
      write_error <= 0;
    end if (i_write && !full && !i_reset) begin
      mem[addr_write] <= i_data;
      write_error <= 0;
      addr_write <= addr_write + 1'b1;
      addr_next <= addr_next + 1'b1;
    end else if (i_write && full && !i_reset) begin
      write_error <= 1;
    end else begin
      write_error <= 0;
    end
  end

  always @ (negedge i_clk_read or negedge i_clk_write) begin
    full <= (addr_next == addr_read);
    empty <= (addr_write == addr_read);
    // full_count <= (addr_write - addr_read);
    // free_count <= (addr_read - addr_write);
  end

  assign o_data = data;
  assign o_read_error = read_error;
  assign o_write_error = write_error;
  assign o_empty_n = !empty;
  // assign o_full_count = full_count;
  // assign o_free_count = free_count;

endmodule
