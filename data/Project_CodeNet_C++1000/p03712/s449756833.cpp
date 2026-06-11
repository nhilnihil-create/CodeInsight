#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int H, W;
  cin >> H >> W;

  vector <string> vec(H);
  rep(i,H) cin >> vec.at(i);

  rep(i,W + 2) {
    cout << "#";
  }
  cout << endl;

  rep(i,H){
    cout << "#";
    cout << vec.at(i);
    cout << "#" << endl;
  }

  rep(i,W + 2) {
    cout << "#";
  }
  cout << endl;
}
