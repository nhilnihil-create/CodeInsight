#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vec>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  ll n;
  cin >> n;
  vec x(n);
  for(ll i=0;i<n;i++)cin >> x[i];
  ll l;
  cin >> l;

  mat dp(n+1,vec(21,0));
  for(ll i=0;i<n;i++){
    dp[i][0]=prev(upper_bound(x.begin(),x.end(),x[i]+l))-x.begin();
  }

  //cout << 5 << endl;

  for(ll i=0;i<20;i++){
    for(ll j=0;j<n;j++){
      dp[j][i+1]=dp[dp[j][i]][i];
    }
  }

  //cout << 5 << endl;

  ll q;
  cin >> q;

  vec ans;

  for(ll i=0;i<q;i++){
    ll a,b,c;
    cin >> a >> b;
    if(b<a)swap(a,b);
    a--;
    b--;

    ll r,l,h;
    r=100000;
    l=0;
    while(abs(r-l)>1){
      h=(r+l)/2;
      c=a;
      for(ll j=20;j>=0;j--){
        if((1<<j)&h){
          c=dp[c][j];
        }
      }
      if(c>=b){
        r=h;
      }
      else{
        l=h;
      }
    }
    ans.push_back(r);
  }

  for(ll i=0;i<q;i++)cout << ans[i] << endl;


}