library verilog;
use verilog.vl_types.all;
entity adder_floating_point is
    port(
        operand_normalized_ieee_a: in     vl_logic_vector(31 downto 0);
        operand_normalized_ieee_b: in     vl_logic_vector(31 downto 0);
        final_sum       : out    vl_logic_vector(31 downto 0);
        finish          : out    vl_logic;
        zero            : out    vl_logic;
        overflow        : out    vl_logic;
        underflow       : out    vl_logic;
        op              : in     vl_logic
    );
end adder_floating_point;
