#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  long long ans{1};
  while(N) {
    ans = ans * N-- % 1000000007;
  }
  cout << ans << endl;
  
  return 0;
}
