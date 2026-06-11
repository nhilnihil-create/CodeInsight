#include <bits/stdc++.h>
#define ll long long 
using namespace std;




int main() {
   #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 ll n; cin>>n; 
 vector<ll>v(n);
 ll sum=0;
 for(int i=0;i<n;i++) {
  cin>>v[i]; sum+=v[i];
 }
 ll m; cin>>m; 
 while(m--){
  ll a,b; cin>>a>>b;
  cout<<sum-v[a-1]+b<<endl;
 }
  return 0;
}
