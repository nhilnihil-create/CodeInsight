#include <bits/stdc++.h>
using namespace std;
struct medi { int x, y, c; };
const int INF = 1e9;

int main() {
    int n, s, t;
    cin >> n >> s >> t;
    vector<medi> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].x >> data[i].y >> data[i].c;
        data[i].x *= t; data[i].y *= s;
    }
    
    int n1 = n/2, n2 = n-n1;
    map<int, int> m1, m2;
    for (int bit = 1; bit < (1<<n1); bit++) {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n1; i++) if (bit&(1<<i)) {
            a += data[i].x; b += data[i].y; c += data[i].c;
        }
        int res = a - b;
        if (m1.count(res)) m1[res] = min(m1[res], c);
        else m1[res] = c;
    }
    for (int bit = 1; bit < (1<<n2); bit++) {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n2; i++) if (bit&(1<<i)) {
            a += data[i+n1].x; b += data[i+n1].y; c += data[i+n1].c;
        }
        int res = a - b;
        if (m2.count(res)) m2[res] = min(m2[res], c);
        else m2[res] = c;
    }
    
    int ans = INF;
    for (const auto& e : m1) {
        int sum, cost; tie(sum, cost) = e;
        if (sum == 0) {
            ans = min(ans, cost);
        } else if (m2.count(-sum)) {
            cost += m2[-sum];
            ans = min(ans, cost);
        }
    }
    for (const auto& e : m2) {
        int sum, cost; tie(sum, cost) = e;
        if (sum == 0) ans = min(ans, cost);
    }
    
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}