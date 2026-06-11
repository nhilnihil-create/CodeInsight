#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <unordered_map>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int MAXN = 234567;
LL psum[MAXN];
int bit[MAXN];

int query(int x) {
    int sum = 0;
    while (x > 0) {
          sum += bit[x];
          x -= (x & (-x));
    }
    return sum;
}

void add(int x, int val, int N) {
     while (x <= N) {
           bit[x] += val;
           x += (x & (-x));
     }
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        int tmp;
        scanf("%d", &tmp);
        psum[i] = psum[i - 1] + tmp - K;
    }
    vector<LL> cand;
    for (int i = 0; i <= N; i++) cand.push_back(psum[i]);
    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());
    LL ans = 0;
    for (int i = 0; i <= N; i++) {
        int rk = upper_bound(cand.begin(), cand.end(), psum[i]) - cand.begin();
        ans += query(rk);
        add(rk, 1, N + 1);
    }
    printf("%lld\n", ans);
    return 0;
}
