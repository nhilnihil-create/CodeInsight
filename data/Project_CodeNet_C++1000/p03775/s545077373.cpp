#include <bits/stdc++.h>
using namespace std;
int a,b;
#define For(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) For(i,0,n)

#define F first
#define S second
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll INF=1e17;


ll gcd(ll x,ll y){
return y? gcd(y,x%y):x;
}


int main(){
  ll n,a=0;
  cin>>n;
  for(int i=pow(n,0.5);i>0;i--){
  if(n%i==0){a=i;break;}
  }
  cout<<to_string(n/a).length()<<endl;
return 0;}