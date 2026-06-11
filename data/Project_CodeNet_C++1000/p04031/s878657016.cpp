#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  
  sort(ALL(A));
  int MIN = INF;
  FOR(i,A[0],A[N-1]+1){
    int sum = 0;
    REP(j,N){
      sum+=(i-A[j])*(i-A[j]);
    }
    MIN = min(MIN,sum);
  }

  cout << MIN << endl;
}