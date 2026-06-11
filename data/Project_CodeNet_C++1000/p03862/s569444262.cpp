#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long long x;
  cin >> N >> x;
  vector<long long> a(N);
  for (int i = 0; i < N; i++) cin >> a.at(i);
  
  long long count = 0;
  for (int i = 0; i < N - 1; i++) {
    long long lhs = a.at(i);
    long long rhs = a.at(i + 1);
    if (lhs + rhs > x) {
      long long sum = lhs + rhs;
      long long sub_candies = sum - x;
      rhs -= sub_candies;
      count += sub_candies;
      if (rhs < 0) rhs = 0;
      a.at(i + 1) = rhs;
    }
  }
  cout << count << endl;
}