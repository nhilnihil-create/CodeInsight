#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

const int MAX = 1000000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const long long INF = 1LL << 60;

int main() {
    ll N;
    string S, C;
    cin >> N >> S;
    C = S;
    while (S.find("()") != S.npos) {
        S.erase(S.find("()"), 2);
    }
    if (S.length() == 0) {
        cout << C << endl;
        return 0;
    }
    if (S.find(")(") == S.npos) {
        if (S[0] == ')') {
            cout << string(S.length(), '(');
            cout << C << endl;
        } else {
            cout << C;
            cout << string(S.length(), ')') << endl;
        }
    } else {
        string left = S.substr(0, S.find(")(") + 1);
        string right = S.substr(S.find(")(") + 1);
        cout << string(left.length(), '(');
        cout << C;
        cout << string(right.length(), ')') << endl;
    }

    return 0;
}
