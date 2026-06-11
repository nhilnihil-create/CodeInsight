#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {
    ll n,m,k; cin >> n >> m >> k;
    string ans = "No";

    rep(i,m+1){
        rep(j,n+1){
            if(i*(n-j) + j*(m-i) == k) ans = "Yes";
        }
    }
    cout << ans;

    return 0;
}
