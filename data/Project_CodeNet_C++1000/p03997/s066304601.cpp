#include<stdio.h>
#include<string.h>
//言語は「C++14(GCC 5.4.1)」
//AtCoder Beginner Contest 45-A

int main(void)
{
	int a, b, h;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &h);
	printf("%d", (a+b)*h/2);
	return 0;
}