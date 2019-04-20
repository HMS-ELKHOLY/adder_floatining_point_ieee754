#include <stdio.h>
#include <stdlib.h>
/*
Author : Hussien Mostafa Said EL-kholy
Date : 7/4/2019 13:18
*/
//contains the same binary data
typedef union container
{float ieee_754;
int binary_decimal;
}f_i;
void Float_binary(char  *c ,float f)
{
f_i contains;
contains.ieee_754=f;
for (int i=31; i>=0;i--)
{//add 48 to convert to ASCII
*(c+i)=contains.binary_decimal%2+48;
contains.binary_decimal=contains.binary_decimal/2;

}
*(c+32)='\0';
//terimnate ASCII
}
int main()
{
char c[33];
float f,f2;
int flag=1;
while (flag==1)
{
    printf("first num :");
    scanf("%f",&f);
    printf("second num :");
    scanf("%f",&f2);
    Float_binary(c,f);
    printf("F1 :  %s  +  ",c);
    Float_binary(c,f2);
    printf("F2 :  %s  =  ",c);
    Float_binary(c,f2+f);
    printf(" result  %s  \n\n  ",c);
    printf("flag :");
    scanf("%d \n",&flag);

}
    return 0;
}
