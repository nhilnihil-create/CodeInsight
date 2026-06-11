#include <iostream> 
#include <algorithm>

using namespace std;

// Count the number of 1s in a bit sequence 
int count(int b) {
  int res = 0;
  while (b != 0) {
    b = b & (b - 1);
    ++res;
  }
  return res;
}

int main() {
  int N, K; cin >> N >> K;
  int a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  long long ans = INT64_MAX;
  for (int i = 0; i < (1 << N); i++) {
    if (count(i) != K) continue; 

    long long cost = 0;
    int requirement = 0; 
    for (int j = 0; j < N; j++) {
      // Be especially careful with & and == in same statement 
      if (((i >> j) & 1) == 0) {
        requirement = max(requirement, a[j] + 1);
        continue;
      } 
      if (requirement > a[j]) {
        cost += requirement - a[j];
        requirement++;
      } else {
        requirement = a[j] + 1;
      }
    }

    ans = min(ans, cost);
  }

  cout << ans << endl;
}