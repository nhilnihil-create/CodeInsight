#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    map<int, int> ma;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        ma[a]++;
        ma[b]++;
    }

    for (auto m : ma) {
        if (m.second % 2 != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
