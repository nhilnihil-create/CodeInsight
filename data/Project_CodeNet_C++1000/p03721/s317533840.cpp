#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long N, K;
    cin >> N >> K;
    vector<pair<int, int>> p(N);
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        p[i] = make_pair(a, b);
    }
    sort(p.begin(), p.end());

    for (int i = 0; i < N; i++)
    {
        if (K <= p[i].second)
        {
            cout << p[i].first << endl;
            return;
        }
        K -= p[i].second;
    }
}

int main() {
    solve();
    return 0;
}