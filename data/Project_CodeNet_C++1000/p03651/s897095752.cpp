#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int gcd(int a, int b){
	if (a%b == 0) return(b);
	else return(gcd(b, a%b));
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ll multi_gcd = a[0];
    FOR(i, 1, n) multi_gcd = gcd(multi_gcd, a[i]);
    debug(multi_gcd);
    int max = *max_element(all(a));
    if (k % multi_gcd != 0 || k>max){
        puts("IMPOSSIBLE");
    } else {
        puts("POSSIBLE");
    }
}