#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  vector<string> ans({"First","Second"});
  if(n==1){
    cout<<ans[a[0]==1]<<endl;
    return 0;
  }
  while(1){
    Int odd=0;
    for(Int i=0;i<n;i++) odd+=a[i]&1;
    Int even=n-odd;
    if(even&1){
      cout<<ans[0]<<endl;
      return 0;
    }
    if(even+1!=n){
      cout<<ans[1]<<endl;
      return 0;
    }
    for(Int i=0;i<n;i++){
      if(a[i]%2==0) continue;
      if(a[i]==1){
	cout<<ans[1]<<endl;
	return 0;
      }
      a[i]--;
    }
    Int g=a[0];
    for(Int i=0;i<n;i++) g=__gcd(g,a[i]);
    for(Int i=0;i<n;i++) a[i]/=g;
    swap(ans[0],ans[1]);
  }
  return 0;
}
