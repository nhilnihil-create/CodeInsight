#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
  int n,k; cin>>n>>k;
  ll ans =0;
  vector<ll> a(n);
  vector<ll> s1(n+1,0);
  vector<ll> s2(n+1,0);

  for(int i=0; i<n; i++){
    cin>>a[i];
    s1[i+1] = s1[i]+a[i];
    s2[i+1] = s2[i]+ max(a[i],0ll);
  }

  int left,right;
  
  for(int i=0; i<=n-k; i++){
    left = i;
    right = i+k;
    ll comp;
    comp = s2[left]-s2[0]+max(s1[right]-s1[left],0ll)+s2[n]-s2[right];
    ans = max(comp,ans);
  }

  cout<<ans<<endl;

  return 0;
  
}
