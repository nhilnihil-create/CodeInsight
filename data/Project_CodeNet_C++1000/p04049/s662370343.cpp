#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#include <chrono>
#include <random>
#include <time.h>
#include <fstream>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define all(c) begin(c),end(c)
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
void print(vec v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(vecll v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}


#define INF 1e9+7
#define LLINF 1e18+7
#define N 250000
ll MOD=1e9+7;

int n,k;
vector<vec> G;
int cnt(int x,int p,int t){
    // cout<<x<<" "<<p<<" "<<t<<endl;
    int res=0;
    if(t>k/2) res++;
    for(auto e:G[x]){
        if(e==p)continue;
        res+=cnt(e,x,t+1);
    }
    return res;
}


main(){
    // int n,k;
    cin>>n>>k;
    vector<pii> que;
    G.resize(n+1);
    rep(i,n-1){
        int a,b;cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
        que.pb({a,b});
    }
    int ans=INF;
    if(k%2){
        for(auto p:que){
            int tmpsum=cnt(p.first,p.second,0)+cnt(p.second,p.first,0);
            ans=min(ans,tmpsum);
        }
    }
    else{
        rep2(i,1,n){
            ans=min(ans,cnt(i,0,0));
        }
    }
    cout<<ans<<endl;

}