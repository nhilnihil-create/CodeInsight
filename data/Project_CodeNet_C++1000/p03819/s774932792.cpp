#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300300;

int N, M;
vector<int> divs[MAXN];
vector<int> add[MAXN];
vector<int> delt[MAXN];

int ft[MAXN];
int ans[MAXN];

void addf(int p, int val) {
   for (; p <= M; p += p & -p) ft[p] += val;
}

int getf(int p) {
   int ans = 0;
   for (; p > 0; p -= p & -p) {
      ans += ft[p];
   }
   return ans;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N >> M;
   for (int i = 1; i <= N; ++i) {
      int l, r;
      cin >> l >> r;
      add[l].emplace_back(l);
      delt[r].emplace_back(l);
   }
   for (int i = 1; i <= M; ++i) {
      for (int j = i; j <= M; j += i) {
         divs[j].emplace_back(i);
      }
   }
   for (int i = 1; i <= M; ++i) {
      for (int v : add[i]) {
         addf(v, +1);
      }
      for (int v : divs[i]) {
         ans[v] += getf(i) - getf(i - v);
      }
      for (int v : delt[i]) {
         addf(v, -1);
      }
   }
   for (int i = 1; i <= M; ++i) {
      cout << ans[i] << "\n";
   }
}
