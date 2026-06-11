#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
  
int main()
{
  ll N, M;
  cin >> N >> M;
  vector<P> A(M);
  REP(i,M) cin >> A[i].first >> A[i].second;
  
  ll BOX[N];
  REP(i,N){
    BOX[i]=1;
  }
  set<int> red;
  red.insert(0);
  REP(i,M){
    if(red.count(A[i].first-1)>=1){
      red.insert(A[i].second-1);
      if(BOX[A[i].first-1]==1){
        red.erase(A[i].first-1);
      }
    }
    BOX[A[i].first-1]--;
    BOX[A[i].second-1]++;
  }

  cout << red.size() << endl;
}