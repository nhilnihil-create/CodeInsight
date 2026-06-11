#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

int main() {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i ++) {
                scanf("%d %d", &a[i].first, &a[i].second);
        }
        vector<int> candidate;
        candidate.push_back(k);
        for (int p = 31; p >= 0; p --) {
                if ((k >> p) & 1) {
                        int tmp = k;
                        tmp &= ~(1 << p);
                        for (int q = p - 1; q >= 0; q --) {
                                tmp |= 1 << q;
                        }
                        candidate.push_back(tmp);
                }
        }
        long long ans = 0;
        for (auto it : candidate) {
                long long res = 0;
                for (int i = 0; i < n; i ++) {
                        if (it == (a[i].first | it)) {
                                res += a[i].second;
                        }
                }
                ans = max(ans, res);
        }
        printf("%lld\n", ans);
        return 0;
}

