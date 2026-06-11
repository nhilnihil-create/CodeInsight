#include <stdio.h>
int main ()
{
	int X, A, B, num1, num2;
	scanf ("%d %d %d", &X, &A, &B);
	if (X>A){
		num1= X-A;
	} else if (X<A){
		num1 = A-X;
	}
	if (X>B){
		num2 = X-B;
	} else if (X<B){
		num2 = B-X;
	} 
	if ( num1 < num2 )
	{
		printf ("A");
	} else if ( num1 > num2 )
	{
		printf ("B");
	}
return 0;
}