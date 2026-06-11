#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
  
int main()
{
  int N, T;
  cin >> N >> T;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  
  int sum = 0;
  REP(i,N-1){
    sum+=min(T,A.at(i+1)-A.at(i));
  }

  cout << sum+T << endl;
}