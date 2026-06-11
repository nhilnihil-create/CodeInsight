#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1LL << 30;

int main(){
  ll N, M;
  cin >> N >> M;
  vvll dp(N, vll(N, INF));
  vector<vector<bool>> flag(N, vector<bool>(N, false));
  for(int i = 0; i < M; i++){
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    dp.at(a).at(b) = c;
    dp.at(b).at(a) = c;
    flag.at(a).at(b) = true;
    flag.at(b).at(a) = true;
  }
  for(int i = 0; i < N; i++){
    dp.at(i).at(i) = 0;
  }
  set<P> se;
  for(int k = 0; k < N; k++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if(dp.at(i).at(j) > dp.at(i).at(k) + dp.at(k).at(j)){
          if(flag.at(i).at(j)){
            int ii = i, jj = j;
            if(ii > jj) swap(ii, jj);
            se.insert(P(ii, jj));
          }
          dp.at(i).at(j) = dp.at(i).at(k) + dp.at(k).at(j);
        }
      }
    }
  }
  cout << se.size() << endl;
}