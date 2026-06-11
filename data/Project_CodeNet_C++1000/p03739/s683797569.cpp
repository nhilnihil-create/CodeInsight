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

  vector<int> a(N);
  rep(i, N) {
    cin >> a[i];
  }

  vector<int> bak = a;

  // pattern1. odd position sum is positive.
  long long count = 0;
  if (a[0] >= 0) {
    count += 1 + a[0];
    a[0] = -1;
  }

  long long sum = 0;
  rep(i, N-1) {
    sum += a[i];
    long long next_sum = sum + a[i+1];

    if (i % 2 == 0) {
      if (next_sum <= 0) {
        // next_sum to +1
        count += 1 - next_sum;
        a[i+1] += 1 - next_sum;
      }
    } else {
      if (next_sum >= 0) {
        // next_sum to -1
        count += next_sum + 1;
        a[i+1] -= (next_sum + 1);
      }
    }
  }
  long long count1 = count;

  // pattern2. even position sum is positive.
  a = bak;
  count = 0;
  if (a[0] <= 0) {
    count += 1 - a[0];
    a[0] = 1;
  }

  sum = 0;
  rep(i, N-1) {
    sum += a[i];
    long long next_sum = sum + a[i+1];

    if (i % 2 != 0) {
      if (next_sum <= 0) {
        // next_sum to +1
        count += 1 - next_sum;
        a[i+1] += 1 - next_sum;
      }
    } else {
      if (next_sum >= 0) {
        // next_sum to -1
        count += next_sum + 1;
        a[i+1] -= (next_sum + 1);
      }
    }
  }

  cout << std::min(count1, count) << endl;

  return 0;
}
