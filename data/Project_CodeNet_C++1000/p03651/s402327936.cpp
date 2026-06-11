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

int gcd(int a, int b){
  if (a%b == 0){
    return(b);
  }else{
    return(gcd(b, a%b));
  }
}
int lcm(int a, int b){
  return a * b / gcd(a, b);
}


int main()
{
  ll N,K;
  cin >> N >> K;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  
  sort(ALL(A));

  ll GCD;
  if(N>=2){
    GCD=gcd(A[0],A[1]);
    FOR(i,2,N){
      GCD=gcd(GCD,A[i]);
    }
  }else{
    GCD=A[0];
  }

  if(K%GCD==0&&A[N-1]>=K){
    cout << "POSSIBLE" << endl;
  }else{
    cout << "IMPOSSIBLE" << endl;
  }
}