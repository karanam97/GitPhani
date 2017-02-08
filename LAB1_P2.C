#include<stdio.h>
#include<math.h>
int main()
{
 float sp,cp,v;
 printf("\nEnter cost price:");
 scanf("%f",&cp);
 printf("\nEnter selling price:");
 scanf("%f",&sp);
 v = sp-cp;
 if(v>0)
   printf(" \nYou have made a profit of $ %f",v);
 else if (v==0)
   printf(" \nNo profit no loss");
 else
   printf("\nYou have made a loss of $ %f",-v);
 return 0;
 }
