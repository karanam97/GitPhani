#include<stdio.h>
#include<math.h>

#define pi 3.14

int main(void)
{
 float r;
 printf("enter the radius of circle: ");
 scanf("%f", &r);
 printf("\nArea of circle is: %f",(pi*pow(r,2)));
return 0;
}
