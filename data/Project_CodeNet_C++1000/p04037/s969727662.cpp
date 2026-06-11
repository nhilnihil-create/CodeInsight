#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  sort(a.rbegin(),a.rend());
  Int p=0;
  while(p+1<n && a[p+1]>p+1) p++;
  Int x=(a[p]-p)&1;
  Int y=p;
  while(y<n && a[y]>p) y++;
  Int z=(y-p)&1;
  //cout<<(a[p]-p)<<" "<<(y-p)<<endl;
  if(!x || !z) cout<<"First"<<endl;
  else cout<<"Second"<<endl;
  return 0;
}
