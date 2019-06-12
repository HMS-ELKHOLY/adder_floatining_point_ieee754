module t_div();
//MINUS stands for reg used in module adder_floating_point when   substracting 
    shortreal ar ,br, opr,oprMINUS;//inputs and outputs in floating point represntation 
    reg [31:0] a,b,opexp,opexpMINUS;
    logic [31:0] op,opMINUS;
    reg [31:0] vectornum,errors;
    reg [95:0] testvectors[1000:0];
    logic zero,zeroMINUS;
    logic f,over,under,fMINUS,overMINUS,underMINUS;
    reg fin,clk;
    int counter=0;
    FPU_division m(clk,a,b,op,fin);
    
always 
    begin
        clk =1; #50; clk = 0; #50;
        counter++;
        
    end

initial begin
    $readmemb("DIV.txt", testvectors);
    vectornum = 0; errors = 0;
    $display("%d ",counter )  ;
end

always @(posedge clk)
    begin
      
        if (counter>=52) begin{a,b,opexp} = testvectors[vectornum];
          counter=0;
   end
        
    end

always @(negedge clk)
    begin
      if (fin==1)
        begin
      ar=$bitstoshortreal(a);br=$bitstoshortreal(b);
     
      opr=$bitstoshortreal(op);
      
      $display("a: %b b: %b a/b : %b  a/b EXP %b ",a,b,op,opexp );
      $display("\n   (a/b: %f)-((a/b)expected %f  ) %f",opr,$bitstoshortreal(opexp),$bitstoshortreal(opr-$bitstoshortreal(opexp))) ;               
            vectornum = vectornum +1;
            if(($bitstoshortreal(opr-$bitstoshortreal(opexp))<0.000001&$bitstoshortreal(opr-$bitstoshortreal(opexp))>-0.000001)
              
             )
              $display(" PASSED \n ");
            else
              $display(" NOT PASSED \n ");
            
      
        if(vectornum >99||testvectors[vectornum]===128'bx) begin
              $display("%d test complate with %d errors" , vectornum , errors);
              $finish;
        end
      end
    end
    
endmodule