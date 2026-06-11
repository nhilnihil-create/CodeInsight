#include <bits/stdc++.h>

using namespace std;

#define foru(i, l, r) for(int i = l; i <= r; i++)
#define ford(i, r, l) for(int i = r; i >= l; i--)

const int maxn = 1e5 + 5;
int N, A[maxn], B[maxn], Cnt;
map<int, int> mp;

int main() {
  //  freopen("c.in", "r", stdin);
  //  freopen("c.out", "w", stdout);
  scanf("%d", &N);
  foru(i, 1, N) scanf("%d", &A[i]);
  foru(i, 1, N) B[i] = A[i];
  sort(B + 1, B + N + 1);
  foru(i, 1, N) mp[B[i]] = i;
  foru(i, 1, N) A[i] = mp[A[i]];
  foru(i, 1, N) Cnt += (A[i] & 1) ^ (i & 1);
  printf("%d\n", Cnt >> 1);
  return 0;
}
