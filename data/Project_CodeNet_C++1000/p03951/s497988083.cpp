#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln = '\n';

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int n;
  string s,t;
  cin >> n >> s >> t;

  int cnt = 0;
  rep(i,n){
    bool flag = true;
    rep(j,n-i){
      if(s[i+j]!=t[j]){
        flag = false; break;
      }
    }
    if(flag){
      cnt = n-i;
      break;
    }
  }
  int ans = n*2-cnt;
  cout << ans << ln;
  return 0;
}