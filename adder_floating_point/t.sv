module t();
    shortreal ar ,br, opr,oprMINUS;
    reg clk;
    reg [31:0] a,b,opexp,opexpMINUS;
    logic [31:0] op,opMINUS;
    reg [31:0] vectornum,errors;
    reg [127:0] testvectors[1000:0];

    logic f,over,under,fMINUS,overMINUS,underMINUS;
adder_floating_point m(a,b,op,f,over,under,1'b0);
adder_floating_point m2(a,b,opMINUS,fMINUS,overMINUS,underMINUS,1'b1);

always 
    begin
        clk =1; #5; clk = 0; #5;
    end

initial begin
    $readmemb("SMALL_AND_SMALL.txt", testvectors);
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
      
      $display(" %b %b %b %b %b %b  ",a,b,op,opexp,opMINUS,opexpMINUS);
                      
            vectornum = vectornum +1;
            if(($bitstoshortreal(opr-$bitstoshortreal(opexp))<0.01&$bitstoshortreal(opr-$bitstoshortreal(opexp))>-0.01)&
              $bitstoshortreal(oprMINUS-$bitstoshortreal(opexpMINUS))<0.01&$bitstoshortreal(oprMINUS-$bitstoshortreal(opexpMINUS))>-0.01
             )
              $display(" PASSED \n ");
            else
              $display(" NOT PASSED \n ");
            
      
        if(vectornum >99||testvectors[vectornum]==128'bx) begin
              $display("%d test complate with %d errors" , vectornum , errors);
              $finish;
        end
    end
    
endmodule