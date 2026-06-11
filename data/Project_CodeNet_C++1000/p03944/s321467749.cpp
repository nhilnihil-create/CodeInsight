#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);
int main() {
  int w,h,n;
  cin >> w >> h >> n;
  vector<vector<int>> s(h,vector<int>(w,0));
  rep(i,n){
    int x,y,a;
    cin >> x >> y >> a;
    if(a == 1){
      rep(j,h)rep(k,x) s.at(j).at(k) = 1;
    }
    else if(a == 2){
      rep(j,h)for(int k = x; k < w; k++) s.at(j).at(k) = 1;
    }
    else if(a == 3){
      rep(k,w)rep(j,y) s.at(j).at(k) = 1;
    }
    else{
      rep(k,w)for(int j = y; j < h; j++) s.at(j).at(k) = 1;
    }
  }
  int ans = 0;
  rep(i,h)rep(j,w){
    if(s.at(i).at(j) == 0) ans++;
  }
  cout << ans << endl;
}

