#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
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
  ll N, K;
  cin >> N >> K;
  vll A(N);
  ll g;
  ll m;
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
    if(i==0){
      g = A.at(i);
      m = A.at(i);
    }
    else{
      g = __gcd(g, A.at(i));
      m = max(m, A.at(i));
    }
  }
  if(K <= m && K % g == 0) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
}