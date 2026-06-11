#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;
ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
  string s;
  cin >> s;
  
  int sn = 0, tn = 0;
  for(int i = 0; i < s.size(); ++i){
    if(s[i] == 'S') sn++;
  }
  tn = s.size() - sn;

  int ls = 0, rs = sn, lt = 0, rt = tn;
  int ans = abs(ls - lt) + abs(rs - rt);
  for(int i = 0; i < s.size(); ++i){
    if(s[i] == 'S'){
      ls++;
      rs--;
    }
    else{
      lt++;
      rt--;
    }
    int t = max(0, lt - ls);
    int s = max(0, rs - rt);
    ans = max(ans, t + s);
  }

  cout << ans << endl;
  return 0;
}