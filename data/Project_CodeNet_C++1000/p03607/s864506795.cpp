#include <iostream>
#include <map>
using namespace std;

int main(){
  int n; cin >> n;
  map<int, int> mp;
  for(int i = 0; i < n; ++i){
    int tmp; cin >> tmp;
    mp[tmp]++;
  }
  int ans = 0;
  for(auto p: mp){
    if(p.second % 2 == 1) ans++;
  }
  cout << ans << endl;
  return 0; 
}