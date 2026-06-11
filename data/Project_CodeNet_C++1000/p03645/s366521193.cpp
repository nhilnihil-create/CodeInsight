#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> x(m,vector<int>(2));
  rep(i,m)rep(j,2) cin >> x.at(i).at(j);
  bool ans = false;
  map<int,int> mp;
  rep(i,m){
    if(x.at(i).at(0) == 1) mp[x.at(i).at(1)]++;
    else if(x.at(i).at(1) == n) mp[x.at(i).at(0)]++;
  }
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    if(itr->second == 2) ans = true;
  }
  cout << (ans?"POSSIBLE":"IMPOSSIBLE") << endl;
}