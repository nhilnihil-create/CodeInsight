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

  vector <bool> app(26, false);  //現れたらtrue
  int N = S.length();
  for (int i = 0; i < N; i++){
    app[S[i] - 'a'] = true;
  }
  for (int i = 0; i < 26; i++){
    if (! app[i]){
      cout << char('a' + i) << endl;
      return 0;
    }
  }
  cout << "None" << endl;
  return 0;
}
