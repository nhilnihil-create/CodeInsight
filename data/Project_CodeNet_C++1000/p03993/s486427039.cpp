#include <iostream>
#include <vector>

signed main() {
  int n;
  std::cin >> n;

  std::vector<int> a(n, 0);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];

    if(a[a[i]-1] == i+1)
      ans++;
  }

  std::cout << ans << std::endl;

}
