#include <bits/stdc++.h>

using namespace std;
typedef long long Int;

const int BIT_SIZE = 410000;

int bit[BIT_SIZE + 1];

void add(int pos, int val)
{
  for (pos += 1; pos <= BIT_SIZE; pos += pos & -pos) {
    bit[pos] += val;
  }
}

int get_sum(int pos)
{
  int ret = 0;
  for (pos += 1; pos; pos -= pos & -pos) {
    ret += bit[pos];
  }
  return ret;
}

int main()
{
  int n, k;
  Int a[200000];
  
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
    a[i] -= k;
  }
  
  vector<Int> v;
  Int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    v.push_back(a[i] - sum);
    v.push_back(-sum);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  
  sum = 0;
  Int ans = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    int pos = lower_bound(v.begin(), v.end(), a[i] - sum) - v.begin();
    add(pos, 1);
    pos = lower_bound(v.begin(), v.end(), -sum) - v.begin();
    ans += get_sum(BIT_SIZE - 1) - get_sum(pos - 1);
  }
  
  printf("%lld\n", ans);
  
  return 0;
}