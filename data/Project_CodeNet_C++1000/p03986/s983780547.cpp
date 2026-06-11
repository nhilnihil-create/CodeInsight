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
  ll cnt = 0,res = 0;
  rep(i,n){
    if(s[i] == 'S')cnt++;
    else cnt--;
    if(cnt < 0)res++,cnt = 0;
  }
  res += cnt;
  cout << res << endl;




  return 0;
}