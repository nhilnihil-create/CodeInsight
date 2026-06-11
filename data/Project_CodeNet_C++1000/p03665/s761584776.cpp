#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  int n,p;
  cin >> n >> p;
  ll odd = 0,even = 0;
  rep(i,n){
    int x;cin >> x;
    if(x & 1)odd++;
    else even++;
  }
  if(odd > 0){
    cout << (ll)pow(2,n-1) << endl;
  }else{
    if(p & 1)cout << 0 << endl;
    else cout << (ll)pow(2,n) << endl;
  }




  return 0;
}