#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#define RG register

inline int read()
{
	int data = 0, w = 1; char ch = getchar();
	while(ch != '-' && (!isdigit(ch))) ch = getchar();
	if(ch == '-') w = -1, ch = getchar();
	while(isdigit(ch)) data = data * 10 + (ch ^ 48), ch = getchar();
	return data * w;
}

const char s[] = "RGBY";
int n, m, d;

int main()
{
	n = read(), m = read(), d = read();
	for(RG int i = 0; i < n; i++, putchar('\n'))
		for(RG int j = 0, x, y; j < m; j++)
			x = (m + i + j) / d % 2,
			y = (m + i - j) / d % 2,
			putchar(s[2 * x + y]);
	return 0;
}
