#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<int> X(1e6,0);
  int a;
  for(int i = 0; i < N; i++) {
    cin >> a;
    X[a]++;
  }
  int ans = 0;
  for(int i = 1; i < 1e6; i++) {
    ans = max(ans, X[i - 1] + X[i] + X[i + 1]);
  }

  cout << ans << endl;
  return 0;
}
