#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  vector<int> s(N);
  int sum = 0;
  rep(i, N) {
    cin >> s[i];
    sum += s[i];
  }
  
  sort(all(s));
  
  if(sum%10 != 0) {
    cout << sum << endl;
    return 0;
  }
  
  rep(i, N) {
    if((sum-s[i])%10 != 0) {
      cout << sum-s[i] << endl;
      return 0;
    }
  }
  
  cout << 0 << endl;

}