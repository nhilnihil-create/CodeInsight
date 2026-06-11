#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define INF 1e9
// constexpr ll INF = 1LL << 60;

int gcd(int a, int b){
  if(b==0){
    return a;
  }
  return gcd(b, a%b);
}
int main(){
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  int maxa = 0;
  REP(i, N){
    cin >> A[i];
    maxa = max(maxa, A[i]);
  }
  int G = A[0];
  REP(i, N){
    G = gcd(A[i], G);
  }
  if(K % G ==0 && K <= maxa){
    cout << "POSSIBLE" << endl;
  }
  else{
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}

