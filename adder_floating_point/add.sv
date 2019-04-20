module add( input logic signed [3:0] a  ,  input logic signed [3:0] b ,  output logic signed [3:0] c );
assign c=a+b;
//$display("%d %d %d %d"a,b,a+b,c);

endmodule