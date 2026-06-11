#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define MAX_C 1000000001

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  ll cost = 1000000000LL * 30;
  for (int i = 0; i < (1 << (n-1)); i++) {
    ll temp_cost = 0;
    bitset<14>b(i); //一番左は絶対見える
    if (b.count() != k-1) continue; //残りk-1色を見たい
    ll height = a[0];
    for (int j = 0; j < n-1; j++) {
      if (i & (1 << j)) {
        //height = max(height + 1, a[j+1]);
        height++;
        if (height < a[j+1]) height = a[j+1];
        temp_cost += (height - a[j+1]);
      }
      else if (height < a[j+1]) height = a[j+1];
    }
    //cost = min(cost, temp_cost);
    if (cost > temp_cost) cost = temp_cost;
  }

  cout << cost << endl;
}
