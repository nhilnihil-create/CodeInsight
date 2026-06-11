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
  ll N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  sort(ALL(A));
  ll sum=0;
  vector<ll> B(N);
  REP(i,N){
    sum+=A[i];
    B[i]=sum;
  }
  ll cnt = 1;
  REPR(i,N-2){
    if(B[i]*2>=A[i+1]){
      cnt++;
    }else{
      break;
    }
  }

  cout << cnt << endl;
}