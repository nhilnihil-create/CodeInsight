#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <vector>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pb push_back
#define vec vector<int>
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
int n,m;
vector<vector<int>> dist;
vec ans,ma;
void func(int v,int d,int c){
    if(ans[v]==0)ans[v]=c;
    if(d==0||ma[v]>=d)return;
    ma[v]=d;
    REP(x,dist[v]){
        if(ans[x]==0)ans[x]=c;
        func(x,d-1,c);
    }
}
int main(){
    n=in();
    m=in();
    dist=vector<vector<int>>(n,vector<int>());
    rep(i,m){
        int x=in()-1;
        int y=in()-1;
        dist[x].pb(y);
        dist[y].pb(x);
    }
    int q=in();
    vec v(q),d(q),c(q);
    rep3(i,q-1,0){
        v[i]=in()-1;
        d[i]=in();
        c[i]=in();
    }
    ans=vec(n);
    ma=vec(n);
    rep(i,q)func(v[i],d[i],c[i]);
    rep(i,n)cout<<ans[i]<<endl;
}