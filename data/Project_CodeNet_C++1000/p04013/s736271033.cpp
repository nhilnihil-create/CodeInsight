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
  ll N, A;
  cin >> N >> A;
  vll x(N+1, 0);
  for(int i = 1; i <= N; i++){
    cin >> x.at(i);
    x.at(i) -= A;
  }
  vvll dp(N+1, vll(6000, 0)); //i枚目までで平均Aとの過不足がdのとき、dp.at(i).at(d+N*A)に格納
  dp.at(0).at(0+N*A) = 1;
  dp.at(1).at(0+N*A) = 1;
  dp.at(1).at(x.at(1)+N*A) += 1;
  for(int i = 1; i < N; i++){
    for(int j = -1*N*A; j <= N*A ; j++){
      dp.at(i+1).at(j + N*A) += dp.at(i).at(j + N*A);
      if((j-x.at(i+1)) >= -1*N*A && (j-x.at(i+1)) <= N*A) dp.at(i+1).at(j + N*A) += dp.at(i).at(j-x.at(i+1) + N*A);
      dp.at(i+1).at(j + N*A);
    }
  }
  cout << dp.at(N).at(0 + N*A) - 1 << endl;
}