//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <limits>
#include <map>
#include <vector>
#include <queue> 
#define LL long long
#define ft first
#define sd second
#define mp(x,y) make_pair(x,y)
//#define int LL
using namespace std;
const int N   = 3e5+10;
//const int mod = ;
const int INF =numeric_limits<int >::max();

#define rep(i,x,y) for (int i=x;i<=y;++i)
void read(int &x)
{
	x=0;
	char ch=getchar();
	int f=1;
	while (!isdigit(ch)) (ch=='-'?f=-1:0),ch=getchar();
	while ( isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	x*=f;
}
int buf[30];
void write(int x)
{
    if (x<0) putchar('-'),x=-x;
    buf[0]=0;
    while (x) buf[++buf[0]]=x%10,x/=10;
    if (!buf[0]) buf[0]=1,buf[1]=0;
    while (buf[0]) putchar('0'+buf[buf[0]--]);
}

int n,m,l[N],r[N];
int cnt[N];
void wk(int L,int R)
{
	for (int k=1;k<=m;)
	{
		int b=(L-1)/k;
		int c=L-1-k*b;
		int len=b?(c/b+1):100000;
		++cnt[k];--cnt[min(R/(b+1),k+len-1)+1];
		k+=len;		
	}
	return ;
}

signed main()
{
	
	read(n);read(m);
	rep(i,1,n) read(l[i]),read(r[i]);
	rep(i,1,n) wk(l[i],r[i]);
	rep(i,1,m) cnt[i]+=cnt[i-1];
	rep(i,1,m) write(cnt[i]),putchar('\n');
	return 0;
}