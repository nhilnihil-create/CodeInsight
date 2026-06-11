#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a[100001];
vector<int> v[100001];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        v[x%m].push_back(x);
    }

    for (int i = 0; i < m; i++) {
        sort(v[i].begin(), v[i].end());
    }

    long long ans = 0;
    for (int i = 1; i < (m+1)/2; i++) {
        int l = i, r = m-i, cnt = 0;
        if (v[l].size() > v[r].size()) {
            swap(l, r);
        }

        for (int i = 1; i < v[r].size(); i++) {
            if (v[r][i] == v[r][i-1]) {
                cnt++;
                i++;
            }
        }

        int aa = v[l].size(), bb = v[r].size();
        ans += (aa + min(cnt, (bb-aa)/2));
    }
    ans += (v[0].size()/2);
    if (m%2 == 0) {
        ans += (v[m/2].size()/2);
    }

    printf("%lld\n", ans);

    return 0;
}