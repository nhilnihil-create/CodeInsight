#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> l(N);
  rep(i, N) {
    cin >> l[i];
  }

  std::sort(l.begin(), l.end(), std::greater<int>());

  int sum = 0;
  rep(i, K) {
    sum += l[i];
  }

  cout << sum << endl;
  
  return 0;
}
