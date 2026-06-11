#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> s(n);
  int ans = 0;
  for(int i = 0; i < n; i++){
    cin >> s.at(i);
    ans += s.at(i);
  }
  if(ans % 10 != 0){
    cout << ans << endl;
    return 0;
  }
  sort(s.begin(), s.end());
  bool ok = false;
  for(int i = 0; i < n; i++){
    if(s.at(i) % 10 != 0){
      ans -= s.at(i);
      cout << ans << endl;
      ok = true;
    }
    if(ok) break;
  }
  if(!ok) cout << 0 << endl;
}