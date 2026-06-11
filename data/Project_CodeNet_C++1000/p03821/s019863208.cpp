#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int ll

main(){
  int n; cin>>n;
  vector<int> a(n),b(n);
  rep(i,n){
    cin>>a[i]>>b[i];
  }
  int ans=0;
  for(int i=a.size()-1; i>=0; i--){
    if((a[i]+ans)%b[i]!=0) ans+=b[i]-(a[i]+ans)%b[i];
  }
  cout<<ans<<endl;
}
