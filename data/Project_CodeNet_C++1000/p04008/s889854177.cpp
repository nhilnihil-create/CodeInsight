#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,k; cin >> n >> k;
  vector<int> a(n),G[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
    if(i) G[a[i]].push_back(i);
  }

  int f = 0;
  if(a[0] != 0) a[0] = 0,f = 1;

  vector<int> size(n,0);
  function< int(int) > rec =
  [&](int i){
    int ans = 0;
    for(int v : G[i]){
      ans += rec(v);
      size[i] = max(size[i],size[v] + 1);
    }
    if(size[i] == k-1 && a[i] != 0){
      ans++;
      size[i] = -1;
    }
    return ans;
  };
  cout << rec(0) + f << endl;

  return 0;
}
