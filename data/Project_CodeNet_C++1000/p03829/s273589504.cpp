#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iomanip>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001; // > 10^9
const int MOD = (int)1e9 + 7;
const ll INFLL = 1001001001001001001;  // > 10^18
const ll MODLL = (ll)1e9 + 7;
const double EPS = 1e-9;

int main () {
    
    ll n,a,b; cin >>n>>a>>b;
    vector<ll> x(n); rep(i,n) cin >> x[i];

    ll ans = 0;
    for (int i = 0; i < n-1; i++) {
        if ((x[i+1] - x[i])*a < b) {
            ans += (x[i+1] - x[i])*a;
        } else {
            ans += b;
        } 
    }
    
    cout << ans << endl;

    return 0;
}

