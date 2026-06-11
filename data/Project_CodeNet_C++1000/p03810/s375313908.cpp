#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1<<30;
const int mod=1000000007;    
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

ll gcd(ll x,ll y){
  if(x<y)swap(x,y);
  if(x%y)return gcd(y,x%y);
  return y;
  }
bool dp(int n,vector<ll> v){
  ll sum=0 ,cnt=0;
  rep(i,v.size()){
    sum+=v[i];
    sum%=2;
    if(v[i]&1)cnt++;
    }
  if(sum){
    if(!(n&1)) return true;
    if(cnt>2)return false;
    if(v[0]==1)return false;
    rep(i,n){
      if(v[i]&1)v[i]--;
      }
    ll g=v[0];
    rep(i,n-1)g=gcd(g,v[i+1]);
    rep(i,n)v[i]/=g;
    return !dp(n,v);
    }
  else{
    if(n%2)return true;
    return false;
    }
  }

    
int main(){
  int n;cin>>n;
  ll a[n];
  vector<ll> v;
  rep(i,n){
    cin>>a[i];
    }
  sort(a,a+n);
  rep(i,n)v.push_back(a[i]);
  if(dp(n,v))cout<<"First"<<endl;
  else cout<<"Second"<<endl;
  return 0;
  }
