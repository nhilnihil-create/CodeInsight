#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const ll INFS=1e18;
const int MOD=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
  ll n,a,b;
  cin>>n>>a>>b;
  ll ans=0;
  if(a>b){
    cout<<0<<endl;
    return 0;
  }
  if(a==b){
    cout<<1<<endl;
    return 0;
  }
  if(n==1){
    cout<<0<<endl;
    return 0;
  }
  ans=(n-2)*(b-a)+1;
  cout<<ans<<endl;
}