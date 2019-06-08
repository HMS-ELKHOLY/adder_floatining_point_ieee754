#include <stdio.h>
#include <stdlib.h>
//#include <cmath>




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
int main()
{
 // ********************************   
//output special cases     *********
//**********************************    
char c[34];
f_i special [4];
special[0].binary_decimal=0x7f800000;//+inf
special[1].binary_decimal=0xff800000;//-inf
special[2].binary_decimal=0x7f800000;//NAN
special[3].binary_decimal=0xffc00000;//NAN
special[4].binary_decimal=0x0;//0
FILE * fp =fopen("SPECIAL_CASES.txt","w") ;

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
///****************************TSET FILE 1**********************************
///*************************************************************************
///*************************************************************************
    
////printf("_________________LS____________\n");
fp =fopen("SMALL_AND_SMALL.txt","w") ;
srand(RAND_MAX);
for(int i=0;i<10;i++)
{

    for(int j=0;j<10;j++)
    {
        float f1 ;
        float f2;
        float f3;
        f_i random ;
        random.ieee_754=((float)(RAND_MAX)/(float)(rand()))*1000;
        //random.binary_decimal+=rand()%0x31000000;
        f1= random.ieee_754;

        //f1=f1/((float)(RAND_MAX)/(float)(rand()));
        Float_binary(c,random.ieee_754);
        //printf(" %f ++",f1);
        fputs(c,fp);
        f2=random.ieee_754=(float)(RAND_MAX)/(float)(rand())*1000;
        Float_binary(c,f2);
        ////printf("%f == ",f2);

        fputs(c,fp);
        f3=f2+f1;
        Float_binary(c,f3);
        ////printf("%f\n",(f3));

        fputs(c,fp);
        f3=f1-f2;
        Float_binary(c,f3);

        fputs(c,fp);

        fputs("\n",fp);
    }
}
    
///****************************TSET FILE 2**********************************
///*************************************************************************
///*************************************************************************
    
////printf("_________LL______________\n");
fclose(fp);
fp =fopen("LARGE_AND_LARGE.txt","w") ;
srand(RAND_MAX);
for(int i=0;i<10;i++)
{

    for(int j=0;j<10;j++)
    {
        float f1 ;
        float f2;
        float f3;
        f_i random ;
        random.ieee_754=((float)(RAND_MAX)/(float)(rand()%10))*RAND_MAX*RAND_MAX;
        //random.binary_decimal+=rand()%0x31000000;
        f1= random.ieee_754;

        f1=f1/((float)(RAND_MAX)/(float)(rand()));
        Float_binary(c,random.ieee_754);
       // //printf(" %f ++",f1);
        fputs(c,fp);
        f2=random.ieee_754=(float)(RAND_MAX)/(float)(rand()%10)*RAND_MAX/1.005;
        Float_binary(c,f2);
        ////printf("%f == ",f2);

        fputs(c,fp);
        f3=f2+f1;
        Float_binary(c,f3);
        ////printf("%f\n",(f3));

        fputs(c,fp);
        f3=f1-f2;
        Float_binary(c,f3);

        fputs(c,fp);

        fputs("\n",fp);
    }
}
fclose(fp);
///****************************TSET FILE 3**********************************
///*************************************************************************
///*************************************************************************

//printf("_______________LS_________________");
fp =fopen("SMALL_AND_LARGE.txt","w") ;
srand(RAND_MAX);
for(int i=0;i<10;i++)
{

    for(int j=0;j<10;j++)
    {
        float f1 ;
        float f2;
        float f3;
        f_i random ;
        random.ieee_754=((float)(RAND_MAX)/(float)(rand()));
        //random.binary_decimal+=rand()%0x31000000;
        f1= random.ieee_754;

        //f1=f1/((float)(RAND_MAX)/(float)(rand()));
        Float_binary(c,random.ieee_754);
    //    //printf(" %f ++",f1);
        fputs(c,fp);
        f2=random.ieee_754=(float)(RAND_MAX)/(float)(rand()%10)*RAND_MAX;
     //   Float_binary(c,f2);
        //printf("%f == ",f2);

        fputs(c,fp);
        f3=f2+f1;
        Float_binary(c,f3);
      //  //printf("%f\n",(f3));
        f3=f1-f2;
        Float_binary(c,f3);

        fputs(c,fp);

        fputs(c,fp);
        fputs("\n",fp);
    }
}
fclose(fp);

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
