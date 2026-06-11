#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){ 
  //indexのループを検出できますか、という問題
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i], A[i]--;
  vector<int> seen(n); seen[0] = true;
  //ループを検出するか目的地に辿り着くまでの回数を数える
  int cnt = 0, cur = 0;
  while(1){
      int nx = A[cur]; //次の目的地
      if(seen[nx])break;//2週目に入った
      seen[nx] = true;
      cnt++;
      if(nx==1)break; //目的地に到達
      cur = nx;
  }
  if(seen[1])cout << cnt << ln;
  else cout << -1 << ln;
}

