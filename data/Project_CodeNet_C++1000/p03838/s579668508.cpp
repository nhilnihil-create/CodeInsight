//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  ll x,y;cin>>x>>y;
  ll a,b,c,d;
  ll ans;
  if(abs(x)>=abs(y) &&x>0 && y>0)ans=abs(abs(x)-abs(y))+2;
  if(abs(x)<=abs(y) &&x>0 && y>0)ans=abs(abs(x)-abs(y));
  if(abs(x)>=abs(y) &&x<0 && y<0)ans=abs(abs(x)-abs(y));
  if(abs(x)<=abs(y) &&x<0 && y<0)ans=abs(abs(x)-abs(y))+2;
  if(abs(x)>=abs(y) &&x>0 && y<0)ans=abs(abs(x)-abs(y))+1;
  if(abs(x)<=abs(y) &&x>0 && y<0)ans=abs(abs(x)-abs(y))+1;
  if(abs(x)>=abs(y) &&x<0 && y>0)ans=abs(abs(x)-abs(y))+1;
  if(abs(x)<=abs(y) &&x<0 && y>0)ans=abs(abs(x)-abs(y))+1;
  if(x==0&&y>0)ans=y;
  if(x==0&&y<0)ans=abs(y)+1;
  if(y==0&&x<0)ans=abs(x);
  if(y==0&&x>0)ans=abs(x)+1;
  if(x==0 && y==0)ans=0;
  cout<<ans<<endl;
}
  
  