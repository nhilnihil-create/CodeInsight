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
typedef pair<int,int> pi;
typedef vector<int> vi;
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
const int INF=0x3f3f3f3f;

int main()
{
	int n;
	cin>>n;
	vi a(n);
	vi id(n);
	vc<ll> ans(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		id[i]=i;
	}
	sort(id.begin(),id.end(),[&](int i,int j){if(a[i]==a[j]) return i<j;return a[i]>a[j];});
	int cur=n;
	for(int i=0;i<n;i++)
	{
		int nxt;
		if(i==n-1) nxt=0;
		else nxt=a[id[i+1]];
		if(id[i]<cur) cur=id[i];
		ans[cur]+=1LL*(a[id[i]]-nxt)*(i+1);
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<'\n';

}
