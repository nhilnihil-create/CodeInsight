#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define inf 1e9
#define INF 1000000000000000000
#define PI 3.14159265359

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> x(M), y(M), now(N, 1);
    vector<bool> reach(N, false);
    reach[0] = true;
    rep(i, M) {
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
    }

    int cnt = 0;
    rep(i, M) {
        if (reach[x[i]]) {
            reach[y[i]] = true;
            if (now[x[i]] == 1)
                reach[x[i]] = false;
        }
        now[x[i]]--;
        now[y[i]]++;
    }

    rep(i, N) {
        if (reach[i])
            cnt++;
    }

    cout << cnt << endl;
}