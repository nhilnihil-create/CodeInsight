#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
  int h, w; cin >> h >> w;
  vector<vector<char>> c(h+1, vector<char>(w+1, '.'));
  rep(i, h){
    rep(j, w){
      cin >> c.at(i).at(j);
    }
  }

  rep(i, 2*h){
    rep(j, w){
      int t = i/2;
      cout << c.at(t).at(j);
    }
    cout << endl;
  }

  
  return 0;
}
