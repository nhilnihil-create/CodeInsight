#include <bits/stdc++.h>
#define INF 100000000000
#define MOD 1000000007
#define ll long long int
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()



using namespace std;





int main() {
  ll N; cin>>N;
  ll A[N+1] = {};
  REP(i,N) {
    ll a; cin>>a;
    A[a]++;
  }
  ll ans = 1;
  REP(i,N){
    if(A[i] > 2) {cout<<0<<endl;return 0;}
    if(A[i] == 0) continue;
    ans *= A[i];
    ans %= MOD;
  }
  if(A[0] == 2) ans = 0;
  cout<<ans<<endl;


  return 0;
}