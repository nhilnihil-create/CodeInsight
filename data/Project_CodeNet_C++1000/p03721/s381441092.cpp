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

    long long arr_sum = 0;
    for (int i = 0; i < N; i++)
    {
        arr_sum += p[i].second;
        if (arr_sum >= K)
        {
            cout << p[i].first << endl;
            return;
        }
    }
}

int main() {
    solve();
    return 0;
}