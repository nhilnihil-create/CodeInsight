#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
char s[maxn];
int n, cs, ct;
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; ++i)
		if(s[i] == 'S')
			++cs;
		else
		{
			if(cs) --cs;
			else ++ct;
		}
	printf("%d\n", cs + ct);
	return 0;
}
		 