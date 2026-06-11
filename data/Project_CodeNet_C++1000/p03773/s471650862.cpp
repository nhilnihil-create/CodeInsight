#include<stdio.h>
#include<string.h>
//言語は「C++14(GCC 5.4.1)」
//AtCoder Beginner Contest 45-A

int main(void)
{
	int A, B, C;
	scanf("%d", &A);
	scanf("%d", &B);
	C = A + B;
	if (C >= 24)
		C = C - 24;
	printf("%d", C);
	return 0;
}