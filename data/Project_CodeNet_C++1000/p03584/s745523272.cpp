#include <bits/stdc++.h>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a, b;
  for(int i=0; i<n; i++){
    int ea, eb;
    std::cin >> ea >> eb;
    a.push_back(ea);
    b.push_back(eb);
  }
  long ans = 0;
  for(int i=0; i<31; i++){
    if(i != 30 && (k & (1<<i)) == 0) continue;
    int mask = (k | ~(~0<<i)) & ~(1<<i);
    if(i == 30) mask = k;
    long score = 0;
    for(int j=0; j<n; j++)
      if((a[j] | mask) == mask) score += b[j];
    if(score > ans) ans = score;
  }
  std::cout << ans << std::endl;
}