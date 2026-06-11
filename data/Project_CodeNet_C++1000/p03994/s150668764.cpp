#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i ++)
using namespace std;
using ll = long long;
using PL = pair<ll,ll>;
using P = pair<int,int>;
constexpr int INF = 1000000000;
constexpr long long HINF = 1000000000000000;
constexpr long long MOD = 1000000007;// = 998244353;
constexpr double EPS = 1e-4;
constexpr double PI = 3.14159265358979;

int main() {
    string s; cin >> s;
    ll K; cin >> K;

    int N = s.size();
    rep(i,N) {
        if (s[i] == 'a') continue;
        int cost = 26 - (s[i] - 'a');
        if (cost <= K) {
            K -= cost;
            s[i] = 'a';
        }
    }
    if (K > 0) {
        int x = (s.back() - 'a' + K)%26;
        s.back() = 'a' + x;
    }
    cout << s << '\n';
    return 0;
}