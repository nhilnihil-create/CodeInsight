//i
#include <stdio.h>

int main(){
	int x, a, b;
	scanf ("%d %d %d", &x, &a, &b);
	
	int selisihA = a-x;
	
	if (selisihA<0)
	{
		selisihA = selisihA*-1;
	}
	
	int selisihB = b-x;
	
	if (selisihB<0)
	{
		selisihB= selisihB*-1;
	}

	
	if (selisihA<selisihB)
	{
		printf ("A");
	}
	
	else if (selisihB<selisihA)
	{
		printf ("B");
	}
	
	
	return 0;
}