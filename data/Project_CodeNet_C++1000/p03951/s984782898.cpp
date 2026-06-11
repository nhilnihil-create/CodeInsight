#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;
///vector<pair<string, int>>;

int main(){
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<string> moji;
  rep(i, n) {
    moji.push_back(s.substr(i));
  }
  //rep(i ,n) cout << moji[i]  << endl;

  int ans = 2 * n;

  rep(i, n){
    if(moji[i] == t.substr(0, n-i)) {
      ans = 2 * n - moji[i].size();
      break;
    }
  }
  cout << ans << endl;
}
