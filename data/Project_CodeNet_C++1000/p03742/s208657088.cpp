#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
const int inf=1e9+7;
const ll INF=1LL<<58;
const ll mod=1e9+7;


int main(){
  int i,j;
  ll x,y;
  cin>>x>>y;
  if(abs(x-y)<=1){
    cout<<"Brown"<<endl;
  }
  else cout<<"Alice"<<endl;

  return 0;
}