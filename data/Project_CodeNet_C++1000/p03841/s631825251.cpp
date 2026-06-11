#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db double
#define ld long double
#define pii pair<ll,int>
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
inline int rd()
{
	int x=0;char c=gc();while(!isdigit(c))c=gc();
	while(isdigit(c))x=x*10+c-48,c=gc();return x;
}
const int N=605;
int n,b[N*N];pii a[N];
inline void out(){puts("No");exit(0);}
int main()
{
	n=rd();
	rep(i,1,n)a[i].X=rd(),a[i].Y=i,b[a[i].X]=i;
	sort(a+1,a+n+1);
	rep(i,1,n)
	{
		int t=a[i].Y-1;
		rep(j,1,a[i].X-1)
		{
			if(!t)break;
			if(!b[j])b[j]=a[i].Y,t--;
		}
		if(t)out();
	}
	per(i,n,1)
	{
		int t=n-a[i].Y;
		per(j,n*n,a[i].X+1)
		{
			if(!t)break;
			if(!b[j])b[j]=a[i].Y,t--;
		}
		if(t)out();
	}
	puts("Yes");
	rep(i,1,n*n)printf("%d ",b[i]);
	return 0;
}