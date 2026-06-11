#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> x(m);
  vector<int> y(m);
  for(int i = 0; i < m; i++) cin >> x.at(i) >> y.at(i);
  
  map<int, int> cnt;
  for(int i = 0; i < n; i++) cnt[i+1]++;
  set<int> ans;
  ans.insert(1);
  for(int i = 0; i < m; i++){
    int nx = x.at(i), ny = y.at(i);
    cnt[nx]--, cnt[ny]++;
    if(ans.count(nx)){
      ans.insert(ny);
      if(cnt.at(nx) == 0) ans.erase(nx);
    }
  }
  
  cout << ans.size() << endl;
}