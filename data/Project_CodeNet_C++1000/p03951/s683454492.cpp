#include<cstdio>
const int N=105;
int n;char s[N],t[N];
inline int ck(int x)
{
	for(int i=1;i<=x;++i)
		if(s[n-x+i]!=t[i])return 0;
	return 1;
}
int main()
{
	scanf("%d%s%s",&n,s+1,t+1);
	for(int i=n;~i;--i)if(ck(i))
		return printf("%d",2*n-i),0;
	return 0;
}