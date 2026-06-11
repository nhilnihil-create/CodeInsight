#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string X;
  cin >> X;
  int N = X.size();
  int c = 0;
  int LOL = 0;
  vector<int> vec(0);
  rep(i, N) {
    if(X.at(i) == 'X') {
      
    }
    else {
      rep2(j, i, N) {
        if(X.at(i) == X.at(j)) {
          c++;
          vec.push_back(j);
        }
      }
      vec.push_back(i);
      rep(j, vec.size()) {
        X.at(vec.at(j)) = 'X';
      }
      if(c % 2 == 1) {
        LOL++;
        break;
      }
    }
  }
  if(LOL > 0) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}