#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> cnt(N+1);
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }
    for (int i = 1; i <= N; i++) {
        if (cnt[i] % 2 == 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}