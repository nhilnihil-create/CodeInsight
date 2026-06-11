#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

LL n,n2=1,m,a[200010],dat[800010],datx[800010],delta[800010],deltax[800010],ans=1e18;

void pushdown(LL k)
{
	dat[k*2+1]+=delta[k];
	delta[k*2+1]+=delta[k];
	dat[k*2+2]+=delta[k];
	delta[k*2+2]+=delta[k];
	delta[k]=0;
	datx[k*2+1]+=deltax[k];
	deltax[k*2+1]+=deltax[k];
	datx[k*2+2]+=deltax[k];
	deltax[k*2+2]+=deltax[k];
	deltax[k]=0;
}

void upd(LL k,LL lb,LL ub,LL tlb,LL tub,LL val,LL valx)
{
	if(ub<tlb||tub<lb) return;
	if(tlb<=lb&&ub<=tub)
	{
		dat[k]+=val;
		delta[k]+=val;
		datx[k]+=valx;
		deltax[k]+=valx;
		return;
	}
	pushdown(k);
	upd(k*2+1,lb,(lb+ub)/2,tlb,tub,val,valx);
	upd(k*2+2,(lb+ub)/2+1,ub,tlb,tub,val,valx);
	dat[k]=dat[k*2+1]+dat[k*2+2];
	datx[k]=datx[k*2+1]+datx[k*2+2];
}

void getans(LL k,LL lb,LL ub)
{
	if(lb==ub)
	{
		if(1<=lb&&lb<=m) ans=min(ans,dat[k]+datx[k]*lb);
		return;
	}
	pushdown(k);
	getans(k*2+1,lb,(lb+ub)/2);
	getans(k*2+2,(lb+ub)/2+1,ub);
}

int main()
{
	cin>>n>>m;
	while(n2<m+1) n2*=2;
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n-1)
	{
		if(a[i]<a[i+1])
		{
			upd(0,0,n2-1,a[i]+1,a[i+1],a[i+1]+1,-1);
			upd(0,0,n2-1,1,a[i],a[i+1]-a[i],0);
			upd(0,0,n2-1,a[i+1]+1,m,a[i+1]-a[i],0);
		}
		else
		{
			upd(0,0,n2-1,a[i]+1,m,m+a[i+1]+1,-1);
			upd(0,0,n2-1,1,a[i+1],a[i+1]+1,-1);
			upd(0,0,n2-1,a[i+1]+1,a[i],m-a[i]+a[i+1],0);
		}
	}
	getans(0,0,n2-1);
	cout<<ans<<endl;
	return 0;
}