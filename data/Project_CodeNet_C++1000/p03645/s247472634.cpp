#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> v;
  M mp;
  rep(i, m){
    int x, y;
    cin >> x >> y;
    if(x == 1) v.push_back(y);
    else if(y == n) mp[x] = y;
    else{};
  }
  string s = "IMPOSSIBLE";
  rep(i, v.size()){
    if(mp[v[i]] == n) s = "POSSIBLE";
  }
  cout << s << endl;

  return 0;
}