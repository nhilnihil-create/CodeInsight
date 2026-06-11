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

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int MAXN = 123456;
int a[MAXN];

bool check(int N, LL K, int A, int B) {
     LL ans = 0;
     int offs = A - B;
     for (int i = 0; i < N; i++) {
         LL tmp = a[i] - K * B;
         if (tmp > 0) {
             ans += tmp / offs;
             if (tmp % offs) ans++;
         }
     }
     return K >= ans;
}

int main() {
    int N, A, B;
    while (~scanf("%d %d %d", &N, &A, &B)) {
          for (int i = 0; i < N; i++) {
              scanf("%d", &a[i]);
          }
          int l = 1, r = (int)1e9 + 1;
          while (l < r) {
                int mid = (l + r) / 2;
                if (check(N, mid, A, B)) r = mid;
                else l = mid + 1;
          }
          printf("%d\n", l);
    }
    return 0;
}
