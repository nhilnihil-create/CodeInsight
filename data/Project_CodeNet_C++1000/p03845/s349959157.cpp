#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#define mod 1000000007

int main() {
    int n; std::cin >> n;
    std::vector<int> t(n);
    int sum = 0;
    for(int i = 0;i < n; i++) {
        std::cin >> t[i];
        sum += t[i];
    }

    int m; std::cin >> m;
    std::vector<int> p(m), x(m);
    for(int i = 0; i < m; i++) {
        std::cin >> p[i] >> x[i];
    }

    for(int i = 0;i < m; i++) {
      int ans = sum;
      std::cout << ans - t[p[i]-1] + x[i] << "\n"; 
    }


}