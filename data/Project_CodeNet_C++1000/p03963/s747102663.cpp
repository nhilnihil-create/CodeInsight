#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

double dis(pair<long, long> a, pair<long, long> b){
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
  int N, K;
  cin >> N >> K;
  long ans = K*pow(K-1, N-1);
  cout << ans << endl;
}

