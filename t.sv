module t();
//MINUS stands for reg used in module adder_floating_point when   substracting 
    shortreal ar ,br, opr,oprMINUS;//inputs and outputs in floating point represntation 
    reg [31:0] a,b,opexp,opexpMINUS;
    logic [31:0] op,opMINUS;
    reg [31:0] vectornum,errors;
    reg [127:0] testvectors[1000:0];
    logic zero,zeroMINUS;
    logic f,over,under,fMINUS,overMINUS,underMINUS;
    adder_floating_point m(a,b,op,f,zero,over,under,1'b0);
    adder_floating_point m2(a,b,opMINUS,zeroMINUS,fMINUS,overMINUS,underMINUS,1'b1);
    reg clk;
always 
    begin
        clk =1; #5; clk = 0; #5;
    end

initial begin
    $readmemb("SMALL_SMALL.txt", testvectors);
    vectornum = 0; errors = 0;
end

always @(posedge clk)
    begin
      
        #1; {a,b,opexp,opexpMINUS} = testvectors[vectornum];
     
        
    end

always @(negedge clk)
    begin
        ar=$bitstoshortreal(a);br=$bitstoshortreal(b);
     
      opr=$bitstoshortreal(op);
      oprMINUS=$bitstoshortreal(opMINUS);
      
      $display("a: %b b: %b a+b : %b a+b (expected) : %b a-b  %b a-b (expected) %b  ",a,b,op,opexp,opMINUS,opexpMINUS);
      $display("\n a+b-(a+b)expected %f a-b-(a-b)expected %f",$bitstoshortreal(opr-$bitstoshortreal(opexp)),$bitstoshortreal(oprMINUS-$bitstoshortreal(opexpMINUS))) ;               
            vectornum = vectornum +1;
            if(($bitstoshortreal(opr-$bitstoshortreal(opexp))<0.01&$bitstoshortreal(opr-$bitstoshortreal(opexp))>-0.01)&
              $bitstoshortreal(oprMINUS-$bitstoshortreal(opexpMINUS))<0.01&$bitstoshortreal(oprMINUS-$bitstoshortreal(opexpMINUS))>-0.01
             )
              $display(" PASSED \n ");
            else
              $display(" NOT PASSED \n ");
            
      
        if(vectornum >99||testvectors[vectornum]===128'bx) begin
              $display("%d test complate with %d errors" , vectornum , errors);
              $finish;
        end
    end
    
endmodule