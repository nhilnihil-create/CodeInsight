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
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
#define MAX_V 400010
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
template<typename A, size_t NNN, typename T>
void Fill(A (&array)[NNN], const T &val){
    fill( (T*)array, (T*)(array+NNN), val );
}
#define INF 1e9+7
#define LLINF 1e18+7
ll MOD=998244353;
#define N 510100
ll int n,m;
ll int a[N],b[N];
int used[N];
vec G[N];
main(){
    n=in();m=in();
    rep(i,m){
        int a=in(),b=in();
        G[a].pb(b);
        G[b].pb(a);
    }
    used[1]=1;
    vec v1,v2;
    int now=1;
    while(1){
        bool flag=false;
        int a=G[now].size();
        rep(i,a){
            int t=G[now][a-1-i];
            if(used[t]){
                G[now].pop_back();
                continue;
            }
            v1.pb(t);
            used[t]=1;
            now=t;
            flag=true;
            break;
        }
        if(!flag)break;

    }
    now=1;
    while(1){
        bool flag=true;
        int a=G[now].size();
        rep(i,a){
            int t=G[now][a-1-i];
            if(used[t]){
                G[now].pop_back();
                continue;
            }
            v2.pb(t);
            used[t]=1;
            now=t;
            flag=false;
            break;
        }
        if(flag)break;

    }
    cout<<v1.size()+v2.size()+1<<endl;
    rep(i,v2.size()){
        cout<<v2[v2.size()-1-i]<<" ";
    }
    cout<<1<<" ";
    for(auto e:v1){
        cout<<e<<" ";
    }
    return 0;
}