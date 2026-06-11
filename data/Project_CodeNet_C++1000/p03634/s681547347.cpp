#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>
#include <set>
//#include <bits/stdc++.h>

template<typename T> bool chmax(T &a,T b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

template<typename T> bool chmin(T &a,T b){
    if(a>b){
        a=b;
        return true;
    }
    return false;
}

using namespace std;
#define ALL(X) X.begin(),X.end()
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=2147483647;
const ll LLMAX=9223372036854775807;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N;
    cin>>N;
    vll a(N-1),b(N-1),c(N-1);
    vvvll cost(N);
    for(ll i=0;i<N-1;i++){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--;b[i]--;
        cost[a[i]].push_back(vll{b[i],c[i]});
        cost[b[i]].push_back(vll{a[i],c[i]});
    }
    ll Q,K;
    cin>>Q>>K;
    K--;
    vll x(Q),y(Q);
    for(ll i=0;i<Q;i++){
        cin>>x[i]>>y[i];
        x[i]--;y[i]--;
    }
    
    vll distance(N,-1);
    distance[K]=0;
    vll open;
    open.push_back(K);
    while(open.size()>0){
        ll node=open[0];
        open.erase(open.begin());
        for(ll i=0;i<cost[node].size();i++){
            if(distance[cost[node][i][0]]==-1){
                distance[cost[node][i][0]]=distance[node]+cost[node][i][1];
                open.push_back(cost[node][i][0]);
            }
        }
    }
    
    for(ll i=0;i<Q;i++){
        cout<<distance[x[i]]+distance[y[i]]<<endl;
    }
    
    return 0;
}
