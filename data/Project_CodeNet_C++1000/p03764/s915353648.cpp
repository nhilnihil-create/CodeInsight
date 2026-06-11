#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2

using namespace std;
int MOD = 1000000007;
int n,m;
int x[100010] = {0};
int y[100010] = {0};
int xc[100010] = {0};
int yc[100010] = {0};
signed main(){
    cin >> n >> m;
    rep(i,n)cin >> x[i];
    rep(i,m)cin >> y[i];
    rep(i,n-1) xc[i] = (i+1)*(n-i-1);
    rep(i,m-1) yc[i] = (i+1)*(m-i-1);
    int xsum = 0;
    rep(i,n-1){
        xsum += (x[i+1]-x[i])*xc[i]%MOD;
        xsum %= MOD;
    }
    int ysum = 0;
    rep(i,m-1){
        ysum += (y[i+1]-y[i])*yc[i]%MOD;
        ysum %= MOD;
    }
    cout << xsum*ysum%MOD << endl;
    

    
    return 0;
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl 