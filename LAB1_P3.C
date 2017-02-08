#include<stdio.h>

int main()
{
 float op1,op2; 
char op;		
												;
 printf(" \n Enter the operand 1:");
 scanf("%f",&op1);
 printf(" \n Enter the operand 2: ");
 scanf("%f",&op2);
printf(" Enter the operator ");
op=getchar();
 
 switch(op)
  {
   case '+': printf("\n %f %c %f = %f", op1,op,op2,(op1+op2));
	     break;
   case '-': printf("\n %f %c %f = %f", op1,op,op2,(op1-op2));
	     break;
   case '*': printf("\n %f %c %f = %f", op1,op,op2,(op1*op2));
	     break;
   case '/': if(op2!=0)
	     printf("\n %f %c %f = %f", op1,op,op2,(op1/op2));
	     else
	     printf("\nDivision by zero error");
	     break;
   default:  printf("\n Enter a valid operation");
 }
 return 0;
}
