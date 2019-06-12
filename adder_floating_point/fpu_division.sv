
/*
 
Team Members:  
	Hussien Mostafa Said ElKholy
	AbdElRahman Ragab Hashem
	AbdAlla Khalid Kamal Siam
	AbdAlla Mohammad AboElMagd Ali Mohammad ElBasiony
	Mahmmoud hassan Mahmmad
*/

/*
	
created by : 
		Mahmmoud hassan Mahmmad
*/
module FPU_division(input logic clk,
input logic signed [31:0]  operand_normalized_ieee_a , operand_normalized_ieee_b ,//opreands must be enterd normalized
output logic signed [31:0]  final_sum,output finish_op //result

 );
 // first we fill the fraction and exponent of the two floating point
logic [24:0]  dividend; 
logic [7:0]   exponent_dividend ;
logic [24:0]  divisor;
logic [7:0]   exponent_divisor ;

reg [49:0] dividend_copy,divisor_copy,divisor_copy1,diff;

logic [24:0]  Q; //result of first division
wire [24:0] R = dividend_copy[24:0]; //remainder of first division
logic [24:0]  RR; //result of second division

wire [74:0] RR_copy1={25'd0,R,25'd0};// initialize remainder for 2nd division  in lower 24 sb and addition to 25 bit of zero

reg [74:0] RR_copy, diff1;

reg [24:0] nb1; //numper of bits it used  as count
reg  n;
reg [24:0] nb2;//numper of bits it used  as count
wire finish1=!nb1;
wire finish=!nb2;
assign
finish_op=finish;
always @(operand_normalized_ieee_a , operand_normalized_ieee_b )
begin
      nb1=25; 
	  nb2=25;
	  n=1;
	  Q=0; // initialize quotient by zero 
      RR=0	; 
      diff=0;
	  diff1=0;
      RR_copy=0;
	  dividend={1'd0,1'd1,operand_normalized_ieee_a[22:0]}; 
      exponent_dividend = operand_normalized_ieee_a [30:23] ;
      divisor={1'd0,1'd1,operand_normalized_ieee_b[22:0]};
      exponent_divisor = operand_normalized_ieee_b [30:23] ;
	  dividend_copy={25'd0,dividend}; // initialize dividend in lower 24 sb  
	  divisor_copy = {1'd0,divisor,24'd0};// initialize divisor in upper 24 sb but before 1'st subtraction we have SR it one bit 
	  divisor_copy1 = {1'd0,divisor,24'd0};
      end
	  always @(posedge clk )
	 
	  
   if (operand_normalized_ieee_a [30:0]=={8'd1,23'd0}
  &&operand_normalized_ieee_b [30:0]=={8'd1,23'd0})
  final_sum [31:0] ={1'd0,8'd1,22'd0,1'd1}; //result is NAN
   
   //if  two operand are 0
  else if (operand_normalized_ieee_a ==0&&operand_normalized_ieee_b ==0)
  final_sum [31:0] ={1'd0,8'd1,22'd0,1'd1};  //result is NAN
  
  //if   operand_normalized_ieee_b is inf 
  else if (operand_normalized_ieee_b [30:0]=={8'd1,23'd0})
  final_sum = 0; //result is 0
  
  //if   operand_normalized_ieee_b is 0
  else if (operand_normalized_ieee_b [30:0]==0)
  final_sum [31:0] ={1'd0,8'd1,23'd0}; //result is inf

  else 
  begin
  
   if (!finish1)
    begin
		 diff =dividend_copy-divisor_copy;
		 Q= Q<<1 ; //shift left
		   if (!diff[49]) //if diff >0
			 begin
			 dividend_copy=diff;
			 Q[0]=1'd1; //put lsb =1
			 end 
	 
	  divisor_copy=divisor_copy >> 1;
	  nb1=nb1-1; //break loop when nb =0  
   end
   else
   if (!finish)
    begin
	   if (n)
	   begin
	     RR_copy=RR_copy1;
		 end
		 diff1 =RR_copy-divisor_copy1;
		 RR= RR<<1 ; //shift left
		   if (!diff1[74]) //if diff >0
			 begin
			 RR_copy=diff1;
			 RR[0]=1'd1; //put lsb =1
			 end 
	 
	  divisor_copy1=divisor_copy1 >> 1;
	  nb2=nb2-1; //break loop when nb =0 
	  n=0;
   end
    

         
	if (Q==1)
	begin
	    final_sum [22:0] = RR [24:2];
		final_sum [29:23] = exponent_dividend - exponent_divisor-1 ;
	end
	else
	begin
	    final_sum [22:0] = {RR [23:2],1'd0};
		final_sum [29:23] = exponent_dividend -exponent_divisor-2;
		final_sum [30]=1'd0;
	end
	if (exponent_dividend <=exponent_divisor)
	 final_sum [30]=1'd0;
	 else
	 final_sum [30]=1'd1;
	final_sum [31]=operand_normalized_ieee_a[31]^operand_normalized_ieee_b[31];
	end
	
 endmodule
   
   //x"FFFF_FFFF"
	  