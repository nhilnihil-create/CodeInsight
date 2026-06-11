#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

// constexpr int INF = 1e9;
constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;



int main(){
  int N;
  cin >> N;
  vector<pair<int, int>> A(N);
  REP(i, N){
    int a;
    cin >> a;
    A[i] = {a, i};
  }
  sort(A.begin(), A.end());
  int ans = 0;
  REP(i, N){
    if(i % 2 != A[i].second % 2){
      ans++;
    }
  }
  cout << ans / 2 << endl;
  
  return 0;
}