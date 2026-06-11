#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
typedef long long ll;
using namespace std;
void solve(){
  int n; cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    mp[a[i]]++;
  }
  int on = 0, tn = 0;
  for(auto it = mp.begin(); it != mp.end(); it++){
    if(it->second % 2 == 0) tn++;
    else on++;
  }
  int ans = mp.size();
  if(tn % 2 == 1) ans--;
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
