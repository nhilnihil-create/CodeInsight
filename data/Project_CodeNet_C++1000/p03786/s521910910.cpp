#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){

  int n;
  cin >> n;
  vector<ll> v(n);
  rep(i,n)cin >> v[i];
  sort(ALL(v));
  vector<ll> s(n+1,0);
  rep(i,n)s[i+1] = s[i]+v[i];
  for(int i = n-1;i >= 0;i--){
    if(s[i]*2 < v[i]){
      cout << n-i << endl;
      return 0;
    }
  }



  return 0;
}