#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  string w;
  cin >> w;

  vector <int> app(26);  //現れた回数
  int N = w.length();
  rep(i,N){
    app[w[i] - 'a'] ++;
  }
  rep(i,26){
    if (app[i] % 2 != 0){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
