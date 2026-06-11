#include <bits/stdc++.h>

using namespace std;

const int TH = 333;
const int N_ = int(3.1e5);
using pii = pair<int, int>;

int N, M;
int A[N_];
vector<pii> pos[N_];

const int LEAF = 1<<19;
int tree[LEAF + LEAF];

void upd(int l, int r) {
  l += LEAF; r += LEAF;
  while(l <= r) {
    if( l & 1) tree[l] += 1;
    if(~r & 1) tree[r] += 1;
    l = (l + 1) >> 1;
    r = (r - 1) >> 1;
  }
}

int get(int x) {
  int ret = 0;
  x += LEAF;
  while(x > 0) {
    ret += tree[x];
    x >>= 1;
  }
  return ret;
}

int main() {
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; i++) {
    int l, r; scanf("%d%d", &l, &r);
    pos[r - l + 1].emplace_back(l, r); 
    // 길이가 L인 철로는, L >= D이면 무조건 지나감
  }

  int larger = N;
  for(int d = 1; d <= M; d++) {
    for(pii i : pos[d]) {
      upd(i.first, i.second);
      larger -= 1;
    }

    int ret = larger;
    for(int i = d; i <= M; i += d) {
      ret += get(i);
    }
    printf("%d\n", ret);
  }
  return 0;
}