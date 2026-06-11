#include<bits/stdc++.h>
#define N (300009)
using namespace std;

int n,m,l,r,c[N];
vector<int>L[N];

void U(int x,int k) {for (;x<=m; c[x]+=k,x+=(x&-x));}
int Q(int x) {int s=0; for (;x; s+=c[x],x-=(x&-x)); return s;}

int main()
{
	cin>>n>>m;
	for (int i=1; i<=n; ++i)
		cin>>l>>r, L[r-l+1].push_back(l);
	for (int d=1; d<=m; ++d)
	{
		int ans=n;
		for (int i=d; i<=m; i+=d) ans+=Q(i);
		for (int i=0,sz=L[d].size(); i<sz; ++i)
			U(L[d][i],1), U(L[d][i]+d,-1), --n;
		printf("%d\n",ans);
	}
}
