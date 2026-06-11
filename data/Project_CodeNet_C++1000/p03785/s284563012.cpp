#include <bits/stdc++.h>
using namespace std;
main(){
  int n,c,k;cin >> n >> c >> k;
  vector<int> t(n);for(int i=0;i<n;i++) cin >> t[i];
  sort(t.begin(),t.end());
  int ans=0;
  for(int i=0;i<n;){
    ans++;
    int j=i;
    while(i<n && t[i]-t[j]<=k && i-j<c) i++;
  }
  cout << ans << endl;
  return 0;
}