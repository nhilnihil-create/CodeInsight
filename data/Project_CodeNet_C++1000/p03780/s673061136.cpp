#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int N, K;
vector<ll> a;

bool need(int x) {
    if (a[x] >= K) return true; // 1枚でKを超えていたらxは必要

    // a[x]を除いた総和で[K-a[x], K)となるものがあるか調べる
    vector<bool> dp(K);
    dp[0] = true;
    rep(i, N) {
        if (i == x) continue; // a[x]は除く
        for (int j = K - 1; j >= 0; j--) {
            if (j + a[i] >= K) continue; // 総和がKを超えてしまう組み合わせはスキップする
            if (dp[j]) dp[j + a[i]] = true;
        }
    }

    for (int i = K - a[x]; i < K; i++) {
        if (dp[i]) return true;
    }
    return false;
}


int main() {
    cin >> N >> K;
    a.resize(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());

    int l = -1, r = N;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (need(c)) r = c; else l = c;
    }
    cout << r << endl;
}