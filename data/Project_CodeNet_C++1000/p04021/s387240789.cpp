#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> init;
  map<int, int> fin;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    init[a[i]] = i;
  }
  sort(a.begin(), a.end());
  for (int i =0 ; i < n; i++){
    fin[a[i]] = i;
  }
  int ans = 0;
  for (auto it = init.begin(); it != init.end(); it++){
    if (it->second % 2 != fin[it->first] % 2)
      ans++;
  }
  cout << ans/2 << '\n';
  
  return 0;

}

