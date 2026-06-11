#include <bits/stdc++.h>
using namespace std;

map<long long, long long> prime_factor(long long N) {
  map<long long, long long> res;
  for (long i = 2; i * i <= N; i++) {
    while (N % i == 0) {
      res[i]++;
      N /= i;
    }
  }
  if (N != 1) {
    res[N] = 1;
  }
  return res;
}

int main() {

  int N;
  cin >> N;

  map<long long, long long> mp;

  for (int i = 1; i <= N; i++){
    map<long long, long long> m = prime_factor(i);
    for (auto item: m) {
      mp[item.first] += item.second;
    }
  }

  long long answer = 1;

  for (auto item: mp) {
    answer *= (item.second + 1);
    answer %= 1000000007;
  }

  cout << answer <<  endl;

  return 0;

}