#include <bits/stdc++.h>
using namespace std;
main(){
  int i;
  int n;cin >> n;
  vector<int> a(110000,0);
  for(i=0;i<n;i++){
    int d;
    cin >> d;
    a[d]++;
  }
  priority_queue<int> ans;
  for(i=0;i<110000;i++){
    int L=a[i]+a[i-1]+a[i+1];
    ans.push(L);
  }
  cout << ans.top() <<endl;
  return 0;
}