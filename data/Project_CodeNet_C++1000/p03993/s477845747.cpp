#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N, ans = 0;
    cin >> N;
    vector<int> a(N);
    rep(i, N) {
        cin >> a[i];
        a[i]--;
    }
    rep(i, N) {
        if (a[a[i]] == i) ans++;
    }
    cout << ans / 2 << "\n";
}