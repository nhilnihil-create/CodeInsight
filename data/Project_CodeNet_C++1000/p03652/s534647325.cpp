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
const int MAXN = 345;
int a[MAXN][MAXN];
bool gone[MAXN];
int cnt[MAXN];

bool check(int x, int N, int M) {
     memset(gone, 0, sizeof(gone));
     vector<deque<int>> cand;
     for (int i = 0; i < N; i++) {
         deque<int> tmp;
         for (int j = 0; j < M; j++) {
             tmp.push_back(a[i][j]);
         }
         cand.push_back(tmp);
     }
     for (int i = 0; i < M; i++) {
         memset(cnt, 0, sizeof(cnt));
         for (int j = 0; j < N; j++) {
             while (gone[cand[j].front()]) {
                   cand[j].pop_front();
             }
             cnt[cand[j].front()]++;
         }
         bool upd = false;
         for (int i = 1; i <= M; i++) {
             if (gone[i]) continue;
             if (cnt[i] > x) {
                gone[i] = 1;
                upd = true;
                break;
             }
         }
         if (!upd) return true;
     }
     return false;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int l = 1, r = N + 1;
    while (l < r) {
          int mid = (l + r) / 2;
          if (check(mid, N, M)) r = mid;
          else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}
