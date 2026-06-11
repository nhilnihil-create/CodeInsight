#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n,m; cin >> n >> m;
  if(2 <= abs(n-m)){
    cout << 0;
  }else{
    ll res1 = 1, res2 = 1;
    rep(i,n){ res1 *= i+1; res1 %= 1000000007; }
    rep(i,m){ res2 *= i+1; res2 %= 1000000007; }
    ll ans = 1;
    if(abs(n-m)==0) ans = 2;
    cout << ans*res1*res2 % 1000000007;
  }
  cout << "\n";
  return 0;
}
