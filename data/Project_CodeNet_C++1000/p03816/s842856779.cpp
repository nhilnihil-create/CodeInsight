#include <iostream>
#include <map>
using namespace std;

void solve(){
  int n; cin >> n; 
  map<int, int> mp;
  int ans = 0;
  for(int i = 0; i < n; ++i){
    int tmp; cin >> tmp;
    mp[tmp]++;
  }
  int cnt = 0;
  int total = mp.size();
  for(auto m: mp){
    if(m.second > 1) cnt += (m.second-1);
  }
  if(cnt%2==0) cout << total << endl;
  else cout << total -1 << endl;
}

int main(){
  solve();
  return 0; 
}