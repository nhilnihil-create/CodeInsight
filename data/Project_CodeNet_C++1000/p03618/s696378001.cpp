#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  string s;
  cin >> s;
  int n = s.size();
  vector<int> v(26,0);
  rep(i,n)v[s[i]-'a']++;
  ll res = 1;
  rep(i,26){
    for(int j = i+1;j < 26;j++){
      res += 1ll*v[i]*v[j];
    }
  }
  cout << res << endl;



  return 0;
}