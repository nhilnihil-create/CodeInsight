#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    int n;
    cin >> n;
    ll sum = 0;
    rep(i,n){
        ll l,r = 0;
        cin >> l >> r;
        sum += (r-l+1);
    }
    cout << sum << endl;
    return 0;
}