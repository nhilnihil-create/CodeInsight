#include<stdio.h>
#include<string.h>
//言語は「C++14(GCC 5.4.1)」
//AtCoder Beginner Contest 58-A

int main(void)
{
	int A, B, C;
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	if (B - A == C - B)
		printf("YES");
	else
		printf("NO");
	return 0;
}