#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;
void solve(){
  int n; cin >> n;
  map<int, int> mp;
  for(int i = 2; i <= n; i++){
    int x = i;
    for(auto itr = mp.begin(); itr != mp.end();){
      if(x % itr->first == 0){
        itr->second++;
        x /= itr->first;
      }
      else itr++;
      if(x == 1) break;
    }
    if(x == i) mp[x]++;
  }
  unsigned long long ans = 1;
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    //cout << itr->first << " " << itr->second << endl;
    ans *= (itr->second + 1);
    ans %= 1000000007;
  }
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
