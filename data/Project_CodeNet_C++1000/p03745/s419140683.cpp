#include <bits/stdc++.h>
using namespace std;
main(){
  int n;cin >> n;
  vector<int> a(n);for(int i=0;i<n;i++) cin >> a[i];
  int ans=0;
  for(int i=0;i<n;i++){
    if(i+1<n && a[i]==a[i+1]){
      while (i+1<n && a[i]==a[i+1]) i++;
    }
    
    if(i+1<n && a[i]<a[i+1]){
      while(i+1<n && a[i]<=a[i+1]) i++;
    } else {
      while(i+1<n && a[i]>=a[i+1]) i++;
    }
    ans++;
  }
  cout << ans <<endl;
  return 0;
}