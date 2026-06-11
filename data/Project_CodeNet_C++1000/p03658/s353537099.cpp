#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

#define ALL(x) begin(x), end(x)

int main() {
  int N, K; 
  cin >> N >> K;
  vector<int> l(N);
  for (int i = 0; i < N; i++) {
    cin >> l[i];
  }
  sort(ALL(l),greater<>());
  cout << accumulate(begin(l),begin(l)+K,0) << endl;
  return 0;
}
