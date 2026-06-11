#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iomanip>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<list>
#include<deque>
#include<bitset>
#include<fstream>
#define ld double
#define ull unsigned long long
#define ll long long
#define pii pair<int,int >
#define iiii pair<int,pii >
#define mp make_pair
#define INF 1000000000
#define MOD 1000000007
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint()
{
	int x=0,p=1;char c=getchar();
	while (c<=32)c=getchar();
	if(c==45)p=-p,c=getchar();
	while (c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//purplesun
const int N=2e5+10;
int n,a[N],b[N];
//
int main()
{
	n=getint();
	rep(i,2*n-1)b[i]=getint();
	int lb=1,rb=2*n;
	while(rb-lb>1)
	{
		int mid=(lb+rb)>>1;
		rep(i,2*n-1)a[i]=(b[i]>=mid);
		int p=n-1,x=a[p],ans=0;
		bool flag=false;
		while(p>0)
		{
			p--;
			if(a[p]==x||a[n*2-p-2]==x)
			{
				ans=x;
				flag=true;
				break;
			}
			x^=1;
		}
		if(!flag)ans=a[0]&1;
		if(ans)lb=mid;
		else rb=mid;
	}
	printf("%d\n",lb);
	return 0;
}