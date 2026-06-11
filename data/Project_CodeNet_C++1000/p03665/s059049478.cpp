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
  int even = 0, odd = 0;
  rep(i,n){
    int a; cin >> a;
    even += 1-a%2;
    odd += a%2;
  }

  vector<vector<ll>> nCr(n+1,vector<ll>(n+1));
  nCr[0][0] = 1;
  rep(i,n) rep(j,i+1){
    nCr[i+1][j+1] += nCr[i][j];
    nCr[i+1][j] += nCr[i][j];
  }
  ll ans = 0;
  rep(i,even+1){
    for(int j = p; j < odd+1; j+=2){
      ans += nCr[odd][j]*nCr[even][i];
    }
  }
  cout << ans;
  cout << "\n";
  return 0;
}
