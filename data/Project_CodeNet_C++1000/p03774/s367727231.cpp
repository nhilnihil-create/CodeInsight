#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N, M;
    cin >> N >> M;

    vector<ll> a(N), b(N), c(M), d(M);
    rep(i, N) {
        cin >> a.at(i) >> b.at(i);
    }
    rep(i, M) {
        cin >> c.at(i) >> d.at(i);
    }

    ll maxValue = pow(10, 10);  // 上限値

    vector<int> minChackPoints(N);

    // O(N * M)
    rep(i, N) {  // 人
        ll minDistance = maxValue;
        int minCheckPoint = 0;
        rep(j, M) {  // 地点
            ll distance = abs(a.at(i) - c.at(j)) + abs(b.at(i) - d.at(j));
            if (distance < minDistance) {
                minDistance = distance;
                minCheckPoint = j;
            }
        }
        minChackPoints.at(i) = minCheckPoint + 1;
    }

    rep(i, N) {
        cout << minChackPoints.at(i) << endl;
    }

    return 0;
}