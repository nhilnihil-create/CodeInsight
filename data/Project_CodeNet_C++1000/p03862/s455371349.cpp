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
 ll n,x; cin>>n>>x; 
 ll count=0;
 vector<ll> v(n);
 for(int i=0;i<n;i++) cin>>v[i];
  for(int j=1;j<n;j++){
     if((v[j]+v[j-1])>x){
      ll t=(v[j]+v[j-1])-x;
      v[j]-=t;
      count+=t;
      if(v[j]<0) v[j]=0;
     }
  }
  cout<<count<<endl;

  return 0;
}
