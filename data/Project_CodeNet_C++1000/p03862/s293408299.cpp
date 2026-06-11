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
  ll N,x;
  cin >> N >> x;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  
  ll ans = 0;
  ll pre = A.at(0);
  if(A.at(0)>x){
    ans+=A.at(0)-x;
    pre=x;
  }
  FOR(i,1,N){
    if(pre+A.at(i)>x){
      ans+=pre+A.at(i)-x;
      pre=x-pre;
    }else{
      pre=A.at(i);
    }
  }

  cout << ans << endl;
}