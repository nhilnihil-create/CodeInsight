#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
  int N; cin >> N;
  long long ans = 0LL;
  vector<int> p(N);
  for(int i = 0; i < N; ++i) {
    cin >> p[i];
  }
  for(int i = 0; i < N; ++i) {
    if(p[i] == i+1) {
      swap(p[i], p[i+1]);
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
