#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

char s[maxn];
int t1,t2,t3,t4;

int main()
{
	scanf("%s",s+1); int len=strlen(s+1);
	rep(i,1,len) if(s[i]=='S') t1=1; else if(s[i]=='N') t2=1;
	else if(s[i]=='W') t3=1; else if(s[i]=='E') t4=1;
	if(t1+t2==1||t3+t4==1) puts("No"); else puts("Yes");
	return 0;
}