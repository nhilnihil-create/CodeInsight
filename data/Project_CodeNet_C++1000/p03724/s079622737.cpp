#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> cnt(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cnt[a]++, cnt[b]++;
    }
    rep(i, N) {
        if(cnt[i] % 2) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}
