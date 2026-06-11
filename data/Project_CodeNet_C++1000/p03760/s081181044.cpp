#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;
const int ny[4] = {-1,1,0,0}, nx[4] = {0,0,-1,1};
int sy,sx,gy,gx;


int main(){
  string o,e; cin >> o >> e;
  bool flg = false;
  string ans = "";
  if(o.size() != e.size()) flg = true;
  rep(i,o.size()){
    ans += o[i];
    if(i == o.size()-1 && flg) break;
    ans += e[i];
  }
  cout << ans << endl;
  return 0;
}
