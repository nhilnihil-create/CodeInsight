#include <cstring>
#include <iostream>
#include <cstdio>

const int M = 500500;
char c[M], ch[M];
int len;

int main()
{
	scanf("%s", c + 1);
	len = strlen(c + 1);
	for (int i = 1; i <= len; ++i)
	{
		switch (c[i])
		{
			case 'b':{
				ch[i] = 'd';
				break;
			}
			case 'd':{
				ch[i] = 'b';
				break;
			}
			case 'p':{
				ch[i] = 'q';
				break;
			}
			case 'q':{
				ch[i] = 'p';
				break;
			}
		}
	}
	for (int i = 1; i <= len; ++i)
		if (c[i] != ch[len - i + 1])
		{
			puts("No");
			return 0;
		}
	puts("Yes");
	return 0;
}