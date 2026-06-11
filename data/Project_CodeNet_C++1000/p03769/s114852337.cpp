#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db long double
#define pii pair<int,int>
#define pli pair<ll,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i)
#define gc() getchar()
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
inline ll rd()
{
	ll x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
int n,ql,qr,q[205];ll s;
void sol(ll s)
{
	if(s==1)return;
	if(s&1){sol(s-1);q[--ql]=++n;}
	else {sol(s/2);q[++qr]=++n;}
}
int main()
{
	s=rd();s++;ql=101;qr=100;n=0;sol(s);
	printf("%d\n",n*2);
	rep(i,ql,qr)printf("%d ",q[i]);
	rep(i,1,n)printf("%d ",i);
	return 0;
}
