#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

FILE * fp;
char c[34];

int sumFileNumber=0;

// need to be edited to be simpler
//need to use functions
/*
Team Members:
    Hussien Mostafa Said ElKholy
    AbdElRahman Ragab Hashem
    AbdAlla Khalid Kamal Siam
    AbdAlla Mohammad AboElMagd Ali Mohammad ElBasiony
    Mahmoud hassan Mahmmad
*/



//Author :hussien mostafa




//contains the same binary data
typedef union container
{float ieee_754;
int binary_decimal;
}f_i;
void Float_binary(char  *c ,float f)
{
//////printf("|||||||  %f  +  ",f);

f_i contains;

contains.ieee_754=f;
int sign=(contains.binary_decimal&0x80000000)==0x80000000;

contains.binary_decimal=contains.binary_decimal&0x7fffffff;
//
//////printf("|||---||||  %d  +  ",contains.binary_decimal);
for (int i=31; i>=0;i--)
{//add 48 to convert to ASCII
*(c+i)=(contains.binary_decimal&0x7fffffff)%2+48;
contains.binary_decimal=contains.binary_decimal/2;
}
if (sign==1)
*(c+0)='1';
*(c+32)='_';
*(c+33)='\0';
//terimnate ASCII
}
int specialCases()
{

 // ********************************
//output special cases     *********
//**********************************
f_i special [4];
special[0].binary_decimal=0x7f800000;//+inf
special[1].binary_decimal=0xff800000;//-inf
special[2].binary_decimal=0x7f800000;//NAN
special[3].binary_decimal=0xffc00000;//NAN
special[4].binary_decimal=0x0;//0
fp =fopen("SPECIAL_CASES.txt","w") ;

for(int i=0;i<5;i++)
{

    for(int j=0;j<5;j++)
    {
        Float_binary(c,special[i].ieee_754);
        fputs(c,fp);
        Float_binary(c,special[j].ieee_754);
        fputs(c,fp);
        Float_binary(c,special[i].ieee_754+special[j].ieee_754);
        fputs(c,fp);
        Float_binary(c,0-special[i].ieee_754+special[j].ieee_754);
        fputs(c,fp);
        fputs("\n",fp);
    }
}
fclose(fp);

    return 1;
}
int specialCases_div()
{

 // ********************************
//output special cases     *********
//**********************************
f_i special [4];
special[0].binary_decimal=0x7f800000;//+inf
special[1].binary_decimal=0xff800000;//-inf
special[2].binary_decimal=0x7f800000;//NAN
special[3].binary_decimal=0xffc00000;//NAN
special[4].binary_decimal=0x0;//0
fp =fopen("SPECIAL_CASES_DIV.txt","w") ;

for(int i=0;i<5;i++)
{

    for(int j=0;j<5;j++)
    {
        Float_binary(c,special[i].ieee_754);
        fputs(c,fp);
        Float_binary(c,special[j].ieee_754);
        fputs(c,fp);
        Float_binary(c,special[i].ieee_754/special[j].ieee_754);
        fputs(c,fp);
        fputs("\n",fp);
    }
}
fclose(fp);

    return 1;
}
int Sum_Case(double k1,
double k2 ,int ratio)
{
ratio=RAND_MAX;

///****************************TSET FILE 1**********************************
///*************************************************************************
///*************************************************************************
char  t [100];
sprintf(t,"sum %d ",sumFileNumber);
////printf("_________________LS____________\n");
fp =fopen("SUM.txt","w") ;
srand(RAND_MAX);
for(int i=0;i<10;i++)
{

    for(int j=0;j<10;j++)
    {
        float f1 ;
        float f2;
        float f3;
        f_i random ;
        random.ieee_754=((float)(RAND_MAX)/(float)(rand()))*pow(RAND_MAX,k1);
        //random.binary_decimal+=rand()%0x31000000;
        f1= random.ieee_754;

        //f1=f1/((float)(RAND_MAX)/(float)(rand()));
        Float_binary(c,random.ieee_754);
        printf(" %f ++",f1);
        fputs(c,fp);
        f2=random.ieee_754*pow(RAND_MAX,k2)*((float)(RAND_MAX)/(float)(rand()%ratio));
        Float_binary(c,f2);
        printf("%f == ",f2);

        fputs(c,fp);
        f3=f2+f1;
        Float_binary(c,f3);
        printf("%f\n",(f3));

        fputs(c,fp);
        f3=f1-f2;
        Float_binary(c,f3);

        fputs(c,fp);

        fputs("\n",fp);
        sumFileNumber++;
    }
}

}
int Div_Case(double k1,
double k2 ,int ratio)
{
ratio=RAND_MAX;

///****************************TSET FILE 2**********************************
///*************************************************************************
///*************************************************************************
char  t [100];
sprintf(t,"DIV %d ",sumFileNumber);
////printf("_________________LS____________\n");
fp =fopen("DIV.txt","w") ;
srand(RAND_MAX);
for(int i=0;i<10;i++)
{

    for(int j=0;j<10;j++)
    {
        float f1 ;
        float f2;
        float f3;
        f_i random ;
        random.ieee_754=((float)(RAND_MAX)/(float)(rand()))*pow(RAND_MAX,k1);
        //random.binary_decimal+=rand()%0x31000000;
        f1= random.ieee_754;

        //f1=f1/((float)(RAND_MAX)/(float)(rand()));
        Float_binary(c,random.ieee_754);
        printf(" %f ++",f1);
        fputs(c,fp);
        f2=random.ieee_754*pow(RAND_MAX,k2)*((float)(RAND_MAX)/(float)(rand()%ratio));
        Float_binary(c,f2);
        printf("%f == ",f2);

        fputs(c,fp);
        f3=f1/f2;
        Float_binary(c,f3);
        printf("%f\n",(f3));

        fputs(c,fp);
        fputs("\n",fp);
        sumFileNumber++;
    }
}}

int main()
{
//Sum_Case(8,-5,RAND_MAX);
Div_Case(1,1,RAND_MAX);
int flag=1;
printf("%s","enter flag");
scanf("%d",&flag);
if (flag==1){
fp=fopen("CustomInput.txt","w") ;
float f,f2;
///****************************custom Input**********************************
///*************************************************************************
///*************************************************************************

do
{

    printf("first num :");
    scanf("%f",&f);
    printf("second num :");
    scanf("%f",&f2);
    Float_binary(c,f);
    fputs(c,fp);
    printf("F1 :  %s  +  ",c);
    Float_binary(c,f2);
    fputs(c,fp);


    printf("F2 :  %s  =  ",c);
    Float_binary(c,f2+f);
    fputs(c,fp);

    printf(" result add  %s  \n\n  ",c);
    Float_binary(c,f-f2);

    printf(" result sub  %s  \n\n  ",c);

    fputs(c,fp);

    printf("flag :");

    scanf("%d",&flag);


    fputs("___\n",fp);

}
while(flag==1);
fclose(fp);

}    return 0;
}
