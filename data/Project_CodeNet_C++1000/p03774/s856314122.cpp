#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#include<algorithm>//next_permutation
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(n) cout << fixed << setprecision(n);
#define large "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define small "abcdefghijklmnopqrstuvwxyz"
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

ll nCr(ll n,ll r){
  if(r == 1) return n;
  else if(r == 0) return 1;
  else return nCr(n-1,r-1)*n/r;
}

int main(){
  ll n,m; cin >> n >> m; vl checkx(m); vl checky(m);
  vl stux(n); vl stuy(n); vl stucheck(n);
  
  rep(i,n){
    cin >> stux[i] >> stuy[i];
  }
  
  rep(i,m){
    cin >> checkx[i] >> checky[i];
  }
  
  rep(i,n){
    ll mindis = 1e17;
    rep(j,m){
      if(mindis > abs(stux[i]-checkx[j])+abs(stuy[i] -checky[j])){
        mindis = abs(stux[i]-checkx[j])+abs(stuy[i]-checky[j]);
        stucheck[i] = j+1;
      }
    }
  }
  
  for(ll x : stucheck){
    cout << x << endl;
  }
  
}