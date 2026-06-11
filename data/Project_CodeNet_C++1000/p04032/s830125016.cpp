#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){

  string s;
  cin >> s;
  P res = make_pair(-2,-2);
  rep(i,s.size()-1)if(s[i] == s[i+1])res = make_pair(i,i+1);
  rep(i,s.size()-2)if(s[i] == s[i+2])res = make_pair(i,i+2);
  cout << res.first+1 << " " << res.second+1 << endl;




  

  return 0;
}