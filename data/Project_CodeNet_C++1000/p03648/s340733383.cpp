#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;

int main(){
  ll K;
  cin >> K;

  int N = 50;
  vector<ll> ret(N, 0);
  REP(i,N) ret[i] = K / N + i;

  REP(i,K % N) {
    REP(j,N) {
      if(j == i) ret[j] += N;
      else --ret[j];
    }
  }

  cout << N << endl;
  REP(i,N) {
    if(i) cout << " ";
    cout << ret[i];
  }
  cout << endl;
  return 0;
}

