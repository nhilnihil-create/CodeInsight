//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll n,x;cin>>n>>x;
  vector<bool>used(2*n-1,false);
  vl ans(2*n-1);
  if(n==2){
    if(x==2){
      cout<<"Yes"<<endl;
      cout<<1<<endl;
      cout<<2<<endl;
      cout<<3<<endl;
    }
    else cout<<"No"<<endl;
  }
  
  else {
    if(x==1||x==2*n-1){
      cout<<"No"<<endl;
      return 0;
    }
    if(x==2){
      ans[n-1]=x;
      ans[n-2]=x+1;
      ans[n]=x-1;
      ans[n+1]=x+2;
      used[x-1]=true;
      used[x+1-1]=true;
      used[x-1-1]=true;
      used[x+2-1]=true;
    }
    else{
      ans[n-1]=x;
      ans[n-2]=x-1;
      ans[n]=x+1;
      ans[n+1]=x-2;
      used[x-1]=true;
      used[x-1-1]=true;
      used[x+1-1]=true;
      used[x-2-1]=true;
    }
    ll j=0;
    rep(i,2*n-1){
      if(ans[i]!=0)continue;
      while(used[j]){
        j++;
      }
      ans[i]=j+1;
      used[j]=true;
    }
    cout<<"Yes"<<endl;
    rep(i,2*n-1){
      cout<<ans[i]<<endl;
    }
  }
}
      
      
  
  