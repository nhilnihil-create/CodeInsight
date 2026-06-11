#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

void solver(ll a,ll b,ll x){
  ll ans;
  if(a%x==0 || b%x==0) ans = 1+(b-a)/x;
  else{
    ans = b/x;
    ans -= a/x;
  }
  cout << ans << endl;
}

/*void solver2(ll a,ll b,ll x){
  ll ans = 0;
  for(ll i = a;i<=b;i++)
  if(i%x==0) ans++;*/
    /*if(i%x==0){
      cout << "i: " << i << endl << "b: " << b << endl;;
      ans++;
      }*//*
  cout << ans << endl;
  }*/

int main(void){
  ll a,b,x; cin >> a >> b >> x;
  //int tester; cin >> tester;
  
  solver(a,b,x);
  
  /*if(tester==0) solver(a,b,x);
    else solver2(a,b,x);*/
  
  return 0;
}
