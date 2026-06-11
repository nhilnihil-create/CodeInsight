#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  ll n,a,b; cin>>n>>a>>b;
  ll d=b-a;
  ll ans;
  if(d<0||(n==1&&d!=0)){ans=0;}
  else if(n==1){ans=1;}
  else{ans=d*(n-2)+1;}
  cout<<ans<<endl;
}
      