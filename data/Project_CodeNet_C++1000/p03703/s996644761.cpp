#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, K, c[maxn];
ll ans, a[maxn], s[maxn];
vector<ll> V;

void add(int p) {
    for (; p <= V.size(); p += p & -p) c[p]++;
}

int sum(int p) {
    int s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]), s[i] = s[i - 1] + a[i] - K;
    }
    for (int i = 0; i <= n; i++) {
        V.push_back(s[i]);
    }
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    for (int i = 0; i <= n; i++) {
        s[i] = lower_bound(V.begin(), V.end(), s[i]) - V.begin() + 1;
    }
    for (int i = 0; i <= n; i++) {
        ans += sum(s[i]), add(s[i]);
    }
    printf("%lld\n", ans);
    return 0;
}