#include <bits/stdc++.h>

using namespace std;

void solve(int N) {
  vector<int> cand({1, 2, 4, 8, 16, 32, 64});
  cout << *(lower_bound(cand.begin(), cand.end(), N + 1) - 1) << endl;
}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  solve(N);

  return 0;
}
