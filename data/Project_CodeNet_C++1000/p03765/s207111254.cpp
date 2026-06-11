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
const int maxn=1e5+7;
int pres[maxn],pret[maxn];
int main()
{
	string s,t;
	cin>>s>>t;
	for(int i=1;i<=s.length();i++)
		pres[i]=pres[i-1]+(s[i-1]=='A'?1:2);
	for(int i=1;i<=t.length();i++)
		pret[i]=pret[i-1]+(t[i-1]=='A'?1:2);
	int q;
	cin>>q;
	while(q--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if((pres[b]-pres[a-1])%3==(pret[d]-pret[c-1])%3)
			cout<<"YES\n";
		else cout<<"NO\n";
	}

}
