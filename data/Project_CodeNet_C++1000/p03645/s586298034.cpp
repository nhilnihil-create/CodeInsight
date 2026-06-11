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
  int N, M;
  cin >> N >> M;

  vector<P> A(M);
  REP(i,M) cin >> A[i].first >> A[i].second;
  unordered_map<int, int> mp;
  REP(i,M){
    if(A[i].first == 1){
      mp[A[i].second]++;
    }
  }
  int flag = 0;
  REP(i,M){
    if(A[i].second==N&&mp[A[i].first]!=0){
      flag = 1;
    }
  }

  if(flag == 0){
    cout << "IMPOSSIBLE" << endl;
  }else{
    cout << "POSSIBLE" << endl;
  }

}