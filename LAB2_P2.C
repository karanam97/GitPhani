#include<stdio.h>

unsigned short int d=0;
void arth()
{
  int b[8],i=0,j,q;
   q = d;
   while(q!=0){
   b[i++]= q% 2;
   q = q/2;
    }
   while(i<8)
    b[i++]=0;
   printf("Equivalent binary value of decimal number %d: ",d);
   for(j = i -1 ;j>=0;j--)
   printf("%d",b[j]);
   printf("\n");
}

void bitw()
{
  unsigned int m=128;   //mask = [10000000]
  printf("Binary Eqivalent : ");
 
  while(m > 0)
   {
    if((d & m) == 0 )
         printf("0");
   else
         printf("1");
   m = m >> 1 ;  // Right Shift
   }
printf("\n");
}

   

int main()
{
    int c;
   
   b: printf("\nEnter any decimal number: ");
    scanf("%hu",&d);
    printf("\n 1. Convert using arthematic operations");
    printf("\n 2. Convert using bitwise operators");
    printf("\nUr choice:");
    scanf("%d",&c);
    if(c==1)
     arth();
    else if (c==2)
     bitw();
    else
     goto b;
        return 0;
  }
   

