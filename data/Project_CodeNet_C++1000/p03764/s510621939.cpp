#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define All(v) (v).begin(),(v).end()
typedef long long ll;

int main(){
    ll n,m;cin >> n >> m;
    vector<ll> x(n),y(m);
    rep(i,n)cin >> x[i];
    rep(i,m)cin >> y[i];
    const int mod = 1e9+7;
    ll xsum=0,ysum=0;
    for(int i=0;i<n-1;i++){
        xsum+=(x[i+1]-x[i])*(i+1)*(n-i-1)%mod;
        xsum%=mod;
    }
    for(int i=0;i<m-1;i++){
        ysum+=(y[i+1]-y[i])*(i+1)*(m-i-1)%mod;
        ysum%=mod;
    }
    cout << xsum*ysum%mod << endl;
    
    return 0;
}