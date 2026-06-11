#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  std::cin >> N;
  
  int i;
  int ans = 0;
  for (i = 0; i < N; i++){
    int a, b;
    std::cin >> a >> b;
    
    ans += (b - a) + 1;
  }
  std::cout << ans << std::endl;
}
