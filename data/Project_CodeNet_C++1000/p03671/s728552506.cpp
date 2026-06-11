#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll a,b,c;
  cin>>a>>b>>c;
  ll ans=min(a+b,b+c);
  ans=min(ans,a+c);
  cout<<ans<<endl;
}
