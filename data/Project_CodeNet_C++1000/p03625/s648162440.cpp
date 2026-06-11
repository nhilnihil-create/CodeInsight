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
  int N;
  cin >> N;

  vector<int> a(N);
  rep(i, N) {
    cin >> a[i];
  }

  std::sort(a.begin(), a.end());

  int before = -1;
  int w = 0;
  int h = 0;
  for(int i = 0; i < N; i++) {
    if (before == a[i]) {
      w = h;
      h = a[i];
      before = -1;
    } else {
      before = a[i];
    }
  }

  cout << (long long)w * h << endl;

  return 0;
}
