#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll H,W; cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  rep(i,H){
    rep(j,W){
      cin >> A.at(i).at(j);
    }
  }
  rep(i,W+2){
    cout << "#";
  }
  cout << endl;
  rep(i,H){
    cout << "#";
    rep(j,W){
      cout << A.at(i).at(j);
    }
    cout << "#" << endl;
  }
  rep(i,W+2){
    cout << "#";
  }
}
  
    