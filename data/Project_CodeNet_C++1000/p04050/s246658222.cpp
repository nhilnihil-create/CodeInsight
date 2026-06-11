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
const int N   = 1e5+10;
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

int cnt,n,m,a[N],pos[N];

signed main()
{
	read(n);read(m);
	rep(i,1,m) 
	{
		read(a[i]);if (a[i]&1) pos[++cnt]=i;
	}
	if (cnt>2) return printf("Impossible"),0;
	if (m==1&&n==1) return printf("1\n1\n1"),0;
	if (m==1) return printf("%d\n2\n%d 1",a[1],a[1]-1),0;
	if (cnt) swap(a[1],a[pos[1]]);
	if (cnt>1) swap(a[m],a[pos[2]]);
	rep(i,1,m) printf("%d%c",a[i],i==m?'\n':' ');
	--a[1],++a[m];
	printf("%d\n",a[1]?m:m-1);
	rep(i,1,m) if (a[i]) printf("%d ",a[i]);
	return 0;
	
}