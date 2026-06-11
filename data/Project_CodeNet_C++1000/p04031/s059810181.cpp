#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int>a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m_cost = 10e5;
    for (int i = -100; i <= 100; i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            tmp += (a[j] - i) * (a[j] - i);
        }
        m_cost = min(m_cost, tmp);
    }
    cout << m_cost;


    return 0;
}
