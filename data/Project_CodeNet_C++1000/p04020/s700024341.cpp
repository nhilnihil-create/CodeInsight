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
  
  ll ans = 0;
  int flag = 0;
  REP(i,N){
    if(flag==0&&A[i]%2==0){
      ans+=A[i]/2;
    }else if(flag==1&&A[i]%2==0){
      ans+=A[i]/2;
      if(A[i]==0){
        flag=0;
      }
    }else if(flag==0&&A[i]%2==1){
      flag=1;
      ans+=A[i]/2;
    }else if(flag==1&&A[i]%2==1){
      flag=0;
      ans+=A[i]/2+1;
    }
  }

  cout << ans << endl;
}