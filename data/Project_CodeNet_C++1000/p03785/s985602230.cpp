#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N, C, K;
  cin >> N >> C >> K;
  vector<int> T(N);
  for (int i=0; i<N; i++) cin >> T[i];
  sort(T.begin(), T.end());
  int i = 0, res = 0;
  while (i<N) {
    res++;
    int start = i; // バスの乗客のうち最も早く着いた客
    while (i<N&&T[i]-T[start]<=K&&i-start<C) i++;
  }
  cout << res << endl;
}