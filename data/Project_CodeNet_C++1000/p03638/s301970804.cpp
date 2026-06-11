#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int h, w; cin >> h >> w;

    int n; cin >> n;

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        p[i] = make_pair(a, i+1);
    }

    sort(p.rbegin(), p.rend());

    vector<int> a;

    for (auto t : p) {
        for (int i = 0; i < t.first; ++i) {
            a.push_back(t.second);
        }
    }

    for (int i = 0; i < h; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < w; ++j) {
                cout << a[i * w + j] << ' ';
            }
        } else {
            for (int j = w-1; j >= 0; --j) {
                cout << a[i * w + j] << ' ';
            }
        }

        cout << endl;
    }
}