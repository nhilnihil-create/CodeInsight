#include <bits/stdc++.h>
using namespace std;

main(){
  int n;cin >> n;
  vector<int> a(n);for(int i=0;i<n;i++) cin >> a[i];
  int cnt_odd = 0;
  string ans="YES";
  for(int i=0;i<n;i++){
    if(a[i]%2 == 1) cnt_odd++; 
  }
  if(cnt_odd%2 == 1){
    ans="NO";
    cout << ans << endl;
    return 0;
  }
  cout << ans <<endl;
  return 0;
} 