#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
  
int main()
{
  int N;
  cin >> N;
  vector<ll> A(3*N);
  REP(i, 3*N) cin >> A[i];

  sort(ALL(A));
  reverse(ALL(A));
  ll sum = 0;
  REP(i,2*N){
    if(i%2 == 1){
      sum+=A.at(i);
    }
  }
  cout << sum << endl;
}