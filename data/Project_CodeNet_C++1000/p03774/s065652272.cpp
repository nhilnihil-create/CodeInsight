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

  vector<P> A(N);
  REP(i,N) cin >> A[i].first >> A[i].second;
  vector<P> B(M);
  REP(i,M) cin >> B[i].first >> B[i].second;

  int check[N] = {0};
  REP(i,N){
    int MIN = INF;
    REP(j,M){
      if(MIN>abs(A.at(i).first-B.at(j).first)+abs(A.at(i).second-B.at(j).second)){
        MIN=abs(A.at(i).first-B.at(j).first)+abs(A.at(i).second-B.at(j).second);
        check[i] = j;
      }
    }
  }

  REP(i,N){
    cout << check[i]+1 << endl;
  }
}