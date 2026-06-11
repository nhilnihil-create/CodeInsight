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
const int maxn=1000;
int dp[maxn][maxn];
bool getans(int x,int y)
{
    if(dp[x][y]!=-1)
        return dp[x][y];
    bool ret=0;
    for(int i=2;i<=x;i+=2)
        if(!getans(x-i,y+i/2))
            ret=1;
    for(int i=2;i<=y;i+=2)
        if(!getans(x+i/2,y-i))
            ret=1;
    return dp[x][y]=ret;
}
int main()
{
    //memset(dp,-1,sizeof(dp));
	ll x,y;
    cin>>x>>y;
    if(x>y) swap(x,y);
    if(y-x<=1) cout<<"Brown\n";
    else cout<<"Alice\n";
    /*for(int x=0;x<50;x++)
    {
        for(int y=0;y<50;y++)
        {
            dbg(x,y,getans(x,y));
        }
    }*/

}