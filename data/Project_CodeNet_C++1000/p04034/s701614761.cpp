#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD=1e9+7;
const long double Pi=acos(-1);
using  P=pair<ll,ll>;
ll gcd(ll a,ll b){//aとbの最大公約数を返す
  if(a%b==0){return b;}
  else{return gcd(b,a%b);}
}
ll lcm(ll a,ll b){//aとbの最小公倍数を返す
  return a*b/gcd(a,b);
}
ll pow(ll x,ll y){//x^yを返す
  ll tmp=x,res=1;
  while(y){
    if(y%2){res=res*tmp%MOD;}
    y>>=1;
    tmp=tmp*tmp%MOD;
  }
  return res;
}
ll nature(ll a){//絶対値を返す
  if(a>=0){return(a);}
  else{return(-1*a);}
}
ll prime(ll a){//素数なら1を返す
  if(a==2){return 1;}
  else if(a%2==0 || a==1){return 0;}
  for(ll i=3;i*i<=a;i+=2){if(a%i==0){return 0;}}
  return 1;
}
int main(){
  ll N,M;
  cin>>N>>M;
  vector<bool> vec(N);
  vector<ll> kosuu(N);
  vec.at(0)=true;
  for(ll i=0;i<N;i++){kosuu.at(i)=1;}
  for(ll i=0;i<M;i++){
    ll a,b;
    cin>>a>>b;
    if(vec.at(a-1) && kosuu.at(a-1)>1){vec.at(b-1)=true;}
    if(vec.at(a-1) && kosuu.at(a-1)==1){vec.at(b-1)=true;vec.at(a-1)=false;}
    kosuu.at(a-1)--;
    kosuu.at(b-1)++;
  }
  ll ans=0;
  for(ll i=0;i<N;i++){
    if(vec.at(i) && kosuu.at(i)>0){ans++;}
  }
  cout<<ans<<endl;
}