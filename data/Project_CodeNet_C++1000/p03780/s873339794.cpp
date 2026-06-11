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
#include <cstdio>
#include <list>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;i++)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
#define vec vector<int>
#define vecll vector<ll>
#define vecstr vector<string>
#define vecch vector<char>
#define vecpii vector<pii>
#define bs binary_search
#define All(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
int n;
int k;
vec a;
bool f(int m){
    vector<vector<bool>> dp(n+1,vector<bool>(k+1));
    dp[0][0]=true;
    rep2(i,1,n)rep2(j,0,k+1)dp[i][j]=i==m||j<a[i]?dp[i-1][j]:dp[i-1][j]||dp[i-1][j-a[i]];
    rep2(j,max(0,k-a[m]),k-1)if(dp[n][j])return false;
    return true;
}
int main(){
    n=in();
    k=in();
    a=vec(n+1);
    rep(i,n)a[i]=in();
    a[n]=0;
    sort(All(a));
    int l=0,r=n+1;
    while(l+1<r){
        int m=(l+r)/2;
        if(f(m))l=m;
        else r=m;
    }
    cout<<l<<endl;
}