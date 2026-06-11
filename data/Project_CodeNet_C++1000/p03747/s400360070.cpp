#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>
#define llong long long
using namespace std;

inline int read()
{
	int x=0; bool f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=0;
	for(; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^'0');
	if(f) return x;
	return -x;
}

const int N = 1e5;
struct Element
{
	int id,dir; llong x,endpos;
} a[N+3];
vector<llong> endpos;
int n; llong m,l;

llong divup(llong x,llong y) {return (x+y-1)/y;}

int main()
{
	scanf("%d%lld%lld",&n,&l,&m);
	for(int i=0; i<n; i++)
	{
		scanf("%lld%d",&a[i].x,&a[i].dir); a[i].id = i;
		if(a[i].dir==1) {a[i].endpos = (a[i].x+m)%l; endpos.push_back(a[i].endpos);}
		else {a[i].endpos = ((a[i].x-m)%l+l)%l; endpos.push_back(a[i].endpos);}
	}
	sort(endpos.begin(),endpos.end());
	if(a[0].dir==1)
	{
		int k; for(k=endpos.size()-1; k>=0; k--) {if(endpos[k]==a[0].endpos) break;}
		llong tot = 0ll;
		for(int i=1; i<n; i++)
		{
			if(a[i].dir==2)
			{
				llong dist = a[i].x-a[0].x;
				llong cnt = (2ll*m-dist+l)/l;
				tot += cnt;
			}
		}
//		printf("tot=%lld k=%d\n",tot,k);
		int sid = ((k-tot)%n+n)%n;
		for(int j=sid; j<sid+n; j++)
		{
			printf("%lld\n",endpos[j%n]);
		}
	}
	else if(a[0].dir==2)
	{
		int k; for(k=0; k<endpos.size(); k++) {if(endpos[k]==a[0].endpos) break;}
		llong tot = 0ll;
		for(int i=1; i<n; i++)
		{
			if(a[i].dir==1)
			{
				llong dist = a[0].x-a[i].x+l;
				llong cnt = (2ll*m-dist+l)/l;
				tot += cnt;
			}
		}
//		printf("tot=%lld k=%d\n",tot,k);
		int sid = ((k+tot)%n+n)%n;
		for(int j=sid; j<sid+n; j++)
		{
			printf("%lld\n",endpos[j%n]);
		}
	}
	return 0;
}
/*
5 20 17
3 1
4 1
5 1
18 2
19 1
*/
/*
5 20 5
5 2
6 1
7 1
18 2
19 1
*/