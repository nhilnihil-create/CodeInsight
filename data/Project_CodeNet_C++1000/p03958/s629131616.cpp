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

    int K, T;
    cin >> K >> T;
    vector<int> v(T);
    rep(i, T) { cin >> v[i]; }

    rep(i, K) {
        sort(all(v), greater<int>());
        if (v[0] != 0 && v[1] != 0)
            v[0]--, v[1]--;
        else if (v[0] == 0) {
            cout << 0 << endl;
            return 0;
        } else {
            cout << v[0] - 1 << endl;
            return 0;
        }
    }
}