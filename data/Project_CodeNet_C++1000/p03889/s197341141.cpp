#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
int read()
{
	int kk(0);
	bool fh=true;
	char ch=getchar();
	for(;ch<'0'||ch>'9';)
	{
		if(ch=='-')fh=false;
		ch=getchar();
	}
	for(;ch>='0'&&ch<='9';)
	{
		kk=(kk<<3)+(kk<<1)+(ch^48);
		ch=getchar();
	}
	return fh?kk:-kk;
}
long long readll()
{
	long long kk(0);
	bool fh=true;
	char ch=getchar();
	for(;ch<'0'||ch>'9';)
	{
		if(ch=='-')fh=false;
		ch=getchar();
	}
	for(;ch>='0'&&ch<='9';)
	{
		kk=(kk<<3)+(kk<<1)+(ch^48);
		ch=getchar();
	}
	return fh?kk:-kk;
}
#define INF 214748364
#define MOD 1000000007
#define MAXN
char s[100010],s1[100010];
map<char,char> mp;
int main()
{
	mp['d']='b';
	mp['b']='d';
	mp['q']='p';
	mp['p']='q';
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++)s1[len-i-1]=s[i];
	for(int i=0;i<len;i++)s1[i]=mp[s1[i]];
	if(strcmp(s,s1)==0)puts("Yes");
	else puts("No");
	return 0;
}