#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>
#define int ll

main(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  vector<int> ra(n+1);
  ra[0]=0;
  for(int i=1; i<=n; i++){
    ra[i]=ra[i-1]+a[i-1];
  }
  int ans=1;
  for(int i=n-1; i>=1; i--){
    if(ra[i]*2 < a[i]) break;
    ans++;
  }
  cout<<ans<<endl;
}
