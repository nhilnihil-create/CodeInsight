#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n,p; cin >> n >> p;
  int odd = 0, even = 0;
  rep(i,n){
    int a; cin >> a;
    even += a%2^1;
    odd += a%2;
  }
  ll ans = 1;
  if(even == n){
    if(p == 0) rep(i,n) ans *= 2;
    else ans = 0;
  }else rep(i,n-1) ans *= 2;
  cout << ans;
  cout << "\n";
  return 0;
}
