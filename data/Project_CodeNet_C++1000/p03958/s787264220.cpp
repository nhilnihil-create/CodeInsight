#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
#define MOD 1000000007

int main() {
    int K, T;
    cin >> K >> T;
    vector<int> V;
    rep(i, T) {
        int x;
        cin >> x;
        V.push_back(x);
    }

    sort(all(V), greater<int>());

    if (V.size() == 1) {
        cout << V[0] - 1 << endl;
        return 0;
    }

    while (true) {
        if (V[1] == 0)
            break;
        int i = 1;
        while (i < T) {
            if (V[0] > V[i]) {
                V[0] -= V[i];
                V[i] = 0;
            } else {
                V[i] -= V[0];
                V[0] = 0;
                break;
            }
            i++;
        }

        sort(all(V), greater<int>());
    }

    int res = V[0] - 1;
    if (res < 0)
        res = 0;
    cout << res << endl;
}