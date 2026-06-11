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
int n;
ll dfs(int x,int cc)
{
	if(x==n+1) return 0;
	ll &ret=dp[x][cc];
	if(ret!=-1) return ret;
	ret=0;
	int sgn=(cc==1?-1:1);
	if(op[x-1][0]=='+')
	{
		ret=max(ret,dfs(x+1,cc)+sgn*a[x]);
		if(cc) ret=max(ret,dfs(x+1,cc-1)+sgn*a[x]);
	}
	else{
		sgn*=-1;
		ret=max(ret,dfs(x+1,cc)+sgn*a[x]);
		if(cc<2) ret=max(ret,dfs(x+1,cc+1)+sgn*a[x]);
	}
	return ret;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i!=n) cin>>op[i];
	}
	op[0]="+";
	cout<<dfs(1,0)<<endl;
}