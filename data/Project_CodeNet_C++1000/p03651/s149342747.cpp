#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
//constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  REP(i, N){
    cin >> A[i];
  }
  ll G = A[0];
  int maxa = A[0];
  REP(i, N){
    G = gcd(G, A[i]);
    maxa = max(maxa, A[i]);
  }
  if(G <= K && K <= maxa && K % G == 0){
    cout << "POSSIBLE" << endl;
  }
  else{
    cout << "IMPOSSIBLE" << endl;
  }
  
  return 0;
}
