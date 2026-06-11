#include<stdio.h>
#include<string.h>
//言語は「C++14(GCC 5.4.1)」
//AtCoder Beginner Contest 63-A

int main(void)
{
	int A, B;
	scanf("%d", &A);
	scanf("%d", &B);
	if (A+B < 10)
		printf("%d", A+B);
	else
		printf("error");
	return 0;
}