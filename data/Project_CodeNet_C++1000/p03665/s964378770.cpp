#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
#define rep1(i,n) for (ll i=1; i<=(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
const ll mod = 998244353;
const double e = 0.000000001;

int main(){
  ll n,p; cin >> n >> p;
  ll n0=0,n1=0;
  rep(i,n){
    ll a; cin >> a;
    if(a%2==0) n0++;
    else n1++;
  }
  if(n1%2==1){
    printf("%.0f",pow(2,n0)*pow(2,n1-1));
    return 0;
  }
  ll choosesum=0;
  ll prev = 1;
  rep(i, (p%2==0 ? (n1/2)+1 : n1/2)){
    ll r = i*2+p;
    if(i!=0){
      prev *= (n1-r+2)*(n1-r+1);
      prev /= r*(r-1);
    }else{
      if(p==1){
        prev *= n1;
      }
    }
    choosesum+=prev;
  }
  printf("%.0f",pow(2,n0)*choosesum);
  return 0;
}