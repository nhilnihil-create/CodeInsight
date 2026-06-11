#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int N;
  cin >> N;

  long long v_t = 0;
  long long v_a = 0;
  
  vector<int> t(N);
  vector<int> a(N);
  rep(i, N) {
    cin >> t[i];
    cin >> a[i];
  }

  rep(i, N) {
    if (v_t <= t[i] && v_a <= a[i]) {
      v_t = t[i];
      v_a = a[i];
    } else {
      long long m = std::max(v_t / t[i], v_a / a[i]);
      while (true) {
        if (v_t <= m * t[i] && v_a <= m * a[i]) {
          v_t = m * t[i];
          v_a = m * a[i];
          break;
        }

        m++;
      }
    }
  }

  cout << v_t + v_a << endl;

  return 0;
}
