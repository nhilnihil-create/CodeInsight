#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
template<typename T> void view(T cont) {std::cout << cont << std::endl;}
template<typename T> void view(T* cont, ll sz) {rep(i, sz) std::cout << cont[i] << " "; std::cout << std::endl;}
template<typename T> void view(const std::vector<T>& v) {for (const auto& f: v) std::cout << f << " "; std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv) { for (const auto& v: vv) {view(v);}}
const long long INF = 1LL<<60;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    ll N; cin >> N;
    string S1, S2; cin >> S1 >> S2;

    ll i;
    ll cnt;
    bool tate;
    if (S1[0] == S2[0]) {
        i = 1;
        cnt = 3;
        tate = true;
    } else {
        i = 2;
        cnt = 6;
        tate = false;
    }
    
    while (i < N) {
        if (S1[i] != S2[i]) {
            if (tate) {
                cnt = cnt * 2 % MOD;
                i += 2;
                tate = false;
            } else {
                cnt = cnt * 3 % MOD;
                i += 2;
                tate = false;
            }
        } else if (S1[i] == S2[i]) {
            if (tate) {
                cnt = cnt * 2 % MOD;
                i++;
                tate = true;
            } else {
                i++;
                tate = true;
            }
        }
    }
    cout << cnt << endl;
}