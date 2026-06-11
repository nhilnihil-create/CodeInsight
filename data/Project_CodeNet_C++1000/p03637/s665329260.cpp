#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b , a % b);
}

ll mod(ll a){
  return (a % 1000000007);
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}


int main(){
  ll n; cin >> n; ll oddcnt,cnt2,cnt4; 
  oddcnt = 0; cnt2 = 0; cnt4 = 0; 
  
  for(ll i=0; i < n; i++){
    ll x; cin >> x;
    if(x % 4 == 0){
      cnt4++;
      continue;
    }
    
    else if(x % 2 == 0) cnt2++;
    
    else oddcnt++;

  }
  
  if((cnt2 == 0 && cnt4 + 1 >= oddcnt ) || (cnt4 >= oddcnt)) cout << "Yes" << endl;
  else cout << "No" << endl;
}