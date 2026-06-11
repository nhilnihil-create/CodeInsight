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
  if(n % 2 == 1) mp[0]++;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    mp[a / 2]++;
  }
  for(int i = 0; i < (n - 1) / 2; i++){
    if(mp[i] != 2){
      cout << 0 << endl;
      return;
    }
  }
  long long ans = 1;
  for(int i = 0; i < (n - 1) / 2; i++){
    ans *= 2;
    ans %= 1000000007;
  }
  if(n % 2 == 0) ans *= 2;
  cout << ans % 1000000007 << endl;
  return;
}

int main(){
  solve();
  return 0;
}
