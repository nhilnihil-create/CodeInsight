#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  ll res = 0;
  for (int i=0; i<N; i++) {
    if (A[i]>=2) {
      res += A[i]/2; // 同じ数字同士でペア
      // 1枚余ったら，次の数字とペアが組めないか試す
      if (A[i]%2!=0&&i+1<N&&A[i+1]>=1) {
        res++;
        A[i+1]--;
      }
    }
    else if (A[i]==1&&i+1<N&&A[i+1]>=1) {
      res++;
      A[i+1]--;
    }
  }
  cout << res << endl;
  return 0;
}