#include<stdio.h>


void factorial()
{
 unsigned short int a=1;
 int i;
 unsigned long int f=1;
 printf("\n Enter a number: ");
 scanf("%hu", &a);
 if(a<13)
  if(a==0)
   printf(" \nFactorial is 1:");
  else
   {
    for(i=1;i<=a;i++)
      f*=i;
    printf("Factorial of %hu is %lu",a,f);
   }
 else
  printf("Output exceeds range");
}

void leap()
{
 unsigned int y=0;
   printf("Enter a year:");
  scanf("%d", &y);
  if ( y%400 == 0)
    printf("%u is a leap year.\n", y);
  else if ( y%100 == 0)
    printf("%u is not a leap year.\n", y);
  else if ( y%4 == 0 )
    printf("%u is a leap year.\n", y);
  else
    printf("%u is not a leap year.\n", y);
}

void comp()
{
 float a=0,b=0;
 printf("Enter any two float number");
 scanf("%f %f",&a,&b);
 printf("Maximum is %f", ((a<b)?b:a));
}

void div()
{
 int a=0,b=1;
 printf("Enter any operand1:");
 scanf("%d",&a);
 printf("Enter any operand2:");
 scanf("%d",&b);
 if(b==0)
  printf("ERROR: Division by zero");
 else
  printf("Quotient is: %f",float (a/b));
}

int main()
{
 char c;
do{
 printf("\n*********Menu***********");
 printf("\nSelect an option");
 printf("\na.Factorial\n");
 printf("b.Leap year or not\n");
 printf("c.Maximum of two numbers\n");
 printf("d. Division of two numbers\n ");
 printf("e.Exit\n");
 printf("Ur choice: ");
 scanf("%c",&c);
 switch(c)
 {
  case 'a': factorial();
          break;
  case 'b': leap();
	  break;
  case 'c': comp();
	  break;
  case 'd': div();
	  break;
  case 'e': break;
 }
}while(c!='e');
 return 0;
 }
