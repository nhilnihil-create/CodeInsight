#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  string S;
  cin >> S;

  vector <bool> app(26, false);
  int N = S.length();
  rep(i,N){
    if (app[S[i] - 'a']){
      cout << "no" << endl;
      return 0;
    }
    app[S[i] - 'a'] = true;
  }
  cout << "yes" << endl;
}
