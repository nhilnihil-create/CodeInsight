#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> roads(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        roads[a - 1]++;
        roads[b - 1]++;
    }
    for (int i = 0; i < n; i++) {
        cout << roads[i] << '\n';
    }
}