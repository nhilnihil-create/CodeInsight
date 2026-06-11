#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, l;
  cin >> n >> l;
  
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  
  bool ans = false;
  int keep;
  for(int i = 1; i < n; i++){
    if(a.at(i - 1) + a.at(i) >= l){
      ans = true;
      keep = i;
      break;
    }
  }
  
  if(ans){
    cout << "Possible\n";
    for(int i = 1; i < keep; i++) cout << i << '\n';
    for(int i = n - 1; i >= keep; i--) cout << i << '\n';
  }
  else cout << "Impossible\n";
}