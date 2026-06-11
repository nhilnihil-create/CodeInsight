#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define fo(i,j,n) for (int i=(j); i < (n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int n; cin >> n;
    vector<string> dom(2);
    rep(i, 2) cin >> dom[i];

    ll res = 1, pos = 0, bef;
    if(dom[0][0] == dom[1][0]) res *= 3, pos++, bef = 1;
    else res *= 6, pos += 2, bef = 2;

    for(int i=pos; i<n; i++){
        int num;
        if(dom[0][i] == dom[1][i]) num = 1; else num = 2;
        if(bef == 2 && num == 2) res = res * 3 % MOD;
        else if(bef == 2 && num == 1) ;
        else res = res * 2 % MOD;
        bef = num;
        if(num == 2) i++;
    }
    cout << res << ln;
}