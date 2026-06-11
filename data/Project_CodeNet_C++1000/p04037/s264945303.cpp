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
inline ll rd()
{
	ll x=0;char c=gc();while(!isdigit(c))c=gc();
	while(isdigit(c))x=x*10+c-48,c=gc();return x;
}
const int N=100005;
int n,a[N];
int main()
{
	n=rd();rep(i,1,n)a[i]=rd();
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	rep(i,1,n)if(a[i+1]<i+1)
	{
		int ans=0;
		for(int j=i+1;a[j]==i;j++)ans^=1;
		ans|=(a[i]-i)&1;
		puts(ans?"First":"Second");
		return 0;
	}
	return 0; 
}
