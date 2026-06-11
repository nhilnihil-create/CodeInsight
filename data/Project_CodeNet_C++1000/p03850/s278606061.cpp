#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
        print(v[i],i==(int)(v.size())-1?suc:2);
}
const int maxn=1e5+7;
ll dp[maxn][3];
int a[maxn];
string op[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i!=n) cin>>op[i];
	}
	memset(dp,-0x3f,sizeof(dp));
	dp[1][0]=a[1];
	for(int i=2;i<=n;i++)
	{
		if(op[i-1][0]=='-')
		{
			for(int j=0;j<3;j++)
			{
				if(j&1)
					dp[i][j]=dp[i-1][j]+a[i];
				else dp[i][j]=dp[i-1][j]-a[i];
				if(j)
					dp[i][j]=max(dp[i][j],dp[i-1][j-1]+(j-1==1?1:-1)*a[i]);
			}
		}
		else{
			for(int j=0;j<3;j++)
			{
				if(j&1)
					dp[i][j]=dp[i-1][j]-a[i];
				else dp[i][j]=dp[i-1][j]+a[i];
				if(j)
					dp[i][j-1]=max(dp[i][j-1],dp[i-1][j]+(j==1?-1:1)*a[i]);
			}
		}
		//dbg(i,dp[i][0],dp[i][1],dp[i][2]);
	}
	cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<endl;
}