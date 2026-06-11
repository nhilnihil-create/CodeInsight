#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll N;cin>>N;
  vector<ll> a(N);rep(i,N) cin>>a[i];
  
  vector<ll> ans(100010,0);
  for(int i=0;i<N;i++){
    if(a[i]==0){
      ans[a[i]]++;
      ans[a[i]+1]++;
    }
    else{
      ans[a[i]-1]++;
      ans[a[i]]++;
      ans[a[i]+1]++;
    }
  }
  
  sort(ans.begin(),ans.end());
  reverse(ans.begin(),ans.end());
  
  cout << ans[0] << endl;
    
}
 