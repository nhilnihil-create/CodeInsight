#include <bits/stdc++.h>

#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<int> visited;
    visited.push_back(1);
    int now = 1;
    int output = 1;
    while (1) {
        now = a[now - 1];
        if (now == 2) {
            cout << output << endl;
            return 0;
        }
        if (find(visited.begin(), visited.end(), now) != visited.end()) {
            cout << -1 << endl;
            return 0;
        }
        visited.push_back(now);
        output++;
    }

    return 0;
}
