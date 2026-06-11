#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<long long> v(n), ans(n, 0);
    map<long long, long long> m;
    map<long long, int> p;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[-v[i]]++;
        if (m[-v[i]] == 1) p[v[i]] = i;
    }
    m[0] = 0;
    long long cnt = 0;
    int cur = n+1;
    long long prev = -1;
    for (auto it: m) {
        long long x = -it.first;
        if (prev != -1) {
            ans[cur] += (prev - x) * cnt;
        }
        cnt += it.second;
        cur = min(cur, p[x]);
        prev = x;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
}