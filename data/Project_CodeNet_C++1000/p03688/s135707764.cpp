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
const int MAXN = 123456;
int a[MAXN];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    sort(a, a + N);
    if (a[N - 1] - a[0] >= 2) return !printf("No\n");
    int cnt0 = 1;
    for (int i = 1; i < N; i++) {
        if (a[i] == a[0]) cnt0++;
    }
    // 2 color distinct
    if (cnt0 != N) {
       int cnt1 = N - cnt0;
       if (cnt0 + 1 <= a[N - 1] && a[N - 1] <= cnt0 + cnt1 / 2) return !printf("Yes\n");
       return !printf("No\n");
    }
    // all the same
    if (a[0] * 2 > N) {
       if (a[0] == N - 1) return !printf("Yes\n");
       return !printf("No\n");
    }
    printf("Yes\n");
    return 0;
}
