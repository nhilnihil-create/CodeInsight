#include <bits/stdc++.h>
using namespace std;

const int kN = 100'000 + 5;
vector<int> s[kN], d[kN];
int fw[kN], ans[kN];

void Modify(int p) {
    for (int i = p; i < kN; i += i & -i) fw[i]++;
}

int Query(int p) {
    int res = 0;
    for (int i = p; i > 0; i -= i & -i) res += fw[i];
    return res;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int l, r; scanf("%d%d", &l, &r);
        s[r].push_back(l);
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= m; j += i) d[j].push_back(i);
    }
    int sum = 0;
    for (int i = 1; i <= m; ++i) {
        for (int v : s[i - 1]) {
            Modify(v);
            sum += 1;
        }
        for (int v : d[i]) ans[v] += sum - Query(i - v);
    }
    for (int v : s[m]) {
        Modify(v);
        sum += 1;
    }
    for (int i = 1; i <= m; ++i) ans[i] += sum - Query(m / i * i);
    for (int i = 1; i <= m; ++i) printf("%d\n", n - ans[i]);
    return 0;
}
