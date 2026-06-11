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
#include <deque>
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

const ll MOD=998244353;

main(){
    int n=in();
    vec p;
    rep(i,n)p.pb(in());
    vector<ll> a(n+1),b(n+1);
    ll now=1;
    rep2(i,1,n-1){
        a[p[i]]+=i;
        b[p[i]]+=i;
    }
    rep2(i,2,n)a[i]+=a[i-1];
    rep3(i,n-1,1)b[i]+=b[i+1];
    vector<ll> A,B;
    rep2(i,1,n)A.pb(i+a[i]);
    rep3(i,n,1)B.pb(i+b[n-i+1]);
    ll minA=LLINF,minB=LLINF;
    rep(i,n)minA=min(minA,A[i]);
    rep(i,n)minB=min(minB,B[i]);
    minA--;minB--;
    rep(i,n)cout<<A[i]-minA<<" ";
    cout<<endl;
    rep(i,n)cout<<B[i]-minB<<" ";
}