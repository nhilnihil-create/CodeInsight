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
        int w, h;
        scanf("%d %d", &w, &h);
        vector<pair<int, bool>> es;
        for (int i = 0; i < w; i ++) {
                int p;
                scanf("%d", &p);
                es.emplace_back(p, true);
        }
        for (int i = 0; i < h; i ++) {
                int q;
                scanf("%d", &q);
                es.emplace_back(q, false);
        }
        sort(es.begin(), es.end());
        long long ans = 0;
        int esp = 0;
        w ++, h ++;
        while (w >= 0 && h >= 0 && esp < (int) es.size()) {
                if (es[esp].second) {
                        ans += (long long) es[esp].first * h;
                        w --;
                } else {
                        ans += (long long) es[esp].first * w;
                        h --;
                }
                esp ++;
        }
        printf("%lld\n", ans);
        return 0;
}
