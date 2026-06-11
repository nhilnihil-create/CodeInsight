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
  ll N,C,K;
  cin >> N >> C >> K;

  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  
  sort(ALL(A));
  ll cnt = 0;
  ll buscnt = 1;
  ll time = A[0];
  REP(i,N-1){
    if(time+K>A[i+1]&&buscnt<C){
      buscnt++;
    }else if(buscnt == C||time+K<A[i+1]){
      buscnt=1;
      cnt++;
      time = A[i+1];
    }
  }
  cout << cnt+1 << endl;
}