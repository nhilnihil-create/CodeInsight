#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, K;
  cin >> N >> K;
  pair<int,int> ab[N];
  for (int i = 0; i < N; i++) {
    cin >> ab[i].first >> ab[i].second;
  }
  sort(ab,ab+N);
  for (long long i = 0, sum = 0; i < N; sum += ab[i++].second) {
    if (sum <= K && K <= sum+ab[i].second) {
      cout << ab[i].first;
      return 0;
    }
  }
}