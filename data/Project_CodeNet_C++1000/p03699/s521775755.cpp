#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  int sum = 0;
  vector<int> score(n);
  rep(i,n) cin >> score[i], sum += score[i];
  if (sum % 10 != 0) cout << sum << endl;
  else {
    sort(score.begin(), score.end());
    rep(i,n) {
      if (score[i] % 10 != 0) {
        cout << sum - score[i] << endl;
        return 0;
      }
    }
    cout << 0 << endl;
  }
  return 0;
}