#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

int main(){
  ll I,O,T,J,L,S,Z;
  cin>>I>>O>>T>>J>>L>>S>>Z;

  ll ans=O+(J/2)*2+(L/2)*2+(I/2)*2;

  if(I%2+L%2+J%2==3)ans+=3;
  else if(I%2+L%2==2&&J>0)ans+=1;
  else if(I%2+J%2==2&&L>0)ans+=1;
  else if(L%2+J%2==2&&I>0)ans+=1;

  cout<<ans<<endl;
  return 0;
}
