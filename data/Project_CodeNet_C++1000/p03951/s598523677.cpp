#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
int n;
char s[maxn], t[maxn];
int f[maxn];
void getf()
{
	for(int i = 2; i <= n; ++i)
	{
		int j = f[i - 1];
		while(j && t[j + 1] != t[i]) j = f[j];
		if(t[j + 1] == t[i]) ++j;
		f[i] = j;
	}
} 
int match()
{
	int j = 0;
	for(int i = 1; i <= n; ++i)
	{
		while(j && t[j + 1] != s[i]) j = f[j];
		if(t[j + 1] == s[i]) ++j;
	}
	return j;
}
int main()
{
	scanf("%d%s%s", &n, s + 1, t + 1);
	getf();
	int ret = match();
	printf("%d\n", 2 * n - ret);
	return 0;
}