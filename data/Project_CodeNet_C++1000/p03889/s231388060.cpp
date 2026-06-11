#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
#include<string>
#include<deque>
#include<map>
#include<cmath>
#include<stack>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;
#define lck_max(a,b) ((a)>(b)?(a):(b))
#define lck_min(a,b) ((a)<(b)?(a):(b))
typedef long long LL;
const int maxn=1e6+7;
const int mod=998244353;
LL hash[maxn];
char s[maxn];
struct hh
{
	LL first,second;
}t;
inline void Hash()
{
	hash[0]=1;
	for(LL i=1;i<=maxn-1000;i++)
	{
		hash[i]=hash[i-1]*13%mod;
	}
}
inline LL read()
{
	LL kr=1,xs=0;
	char ls;
	ls=getchar();
	while(!isdigit(ls))
	{
		if(!(ls^45))
			kr=-1;
		ls=getchar();
	}
	while(isdigit(ls))
	{
		xs=(xs<<1)+(xs<<3)+(ls^48);
		ls=getchar();
	}
	return xs*kr;
}
inline void out(LL xs)
{
	if(!xs) {putchar(48); return;}
	if(xs<0) putchar('-'),xs=-xs;
	int kr[57],ls=0;
	while(xs) kr[++ls]=xs%10,xs/=10;
	while(ls) putchar(kr[ls]+48),ls--;
}
inline void change(LL len)
{
	for(LL i=0;i<len;i++)
	{
		if(s[i]=='b') {s[i]='d';continue;}
		if(s[i]=='d') {s[i]='b';continue;}
		if(s[i]=='q') {s[i]='p';continue;}
		if(s[i]=='p') {s[i]='q';continue;}
	}
}
int main()
{
	Hash();
	scanf("%s",s);
	LL len=strlen(s);
	for(LL i=0;i<len;i++) t.first=(t.first+s[i]*hash[i])%mod;
	change(len);
	for(LL i=len-1;~i;i--) t.second=(t.second+s[i]*hash[len-i-1])%mod;
	if(t.first==t.second) puts("Yes");
	else puts("No");
return 0;
}
