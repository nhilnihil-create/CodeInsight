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
    vector<ll> v(n); rep(i,n) cin >> v[i];
    sort(v.begin(), v.end(), greater<ll>());

    ll res = 0;
    for (int i = 0; i < a; i++) {
        res += v[i];
    }
    double m = ((double)res)/a;
    cout << setprecision(10) << m << endl;

    const ll MAX_N = 100; 
    vector<vector<ll> > c(MAX_N, vector<ll>(MAX_N, 0));
    for (ll i = 0; i < MAX_N; i++) {
        c[i][0] = 1;
        c[i][1] = i;
    }
    for (ll i = 1; i < MAX_N; i++) {
        for (ll j = 1; j <= i; j++) {
            c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    }

    int count0 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == v[a-1]) {
            count0++;
        } 
    }

    if (v[0] != v[a-1]) {
        int count = 0;
        for (int i = 0; i < a; i++) {
            if (v[i] == v[a-1]) {
                count++;
            } 
        }
        cout << c[count0][count] << endl;
    } else {
        ll ans = 0;
        for (int l = a; l <= b; l++) {
            ans += c[count0][l];
        }
        cout << ans << endl;        
    } 

    return 0;
}

