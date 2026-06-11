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
  int N,M;
  cin >> N >> M;
  vector<string> A(N);
  REP(i, N) cin >> A[i];
  vector<string> B(M);
  REP(i, M) cin >> B[i];
  
  int flag2 = 0;
  REP(i,N-M+1){
    REP(j,N-M+1){
      int flag=0;
      REP(k,M){
        REP(l,M){
          if(B.at(k).at(l)!=A.at(i+k).at(j+l)){
            flag=1;
          }
        }
      }
      if(flag==0){
        flag2 = 1;
        break;
      }
    }
    if(flag2==1){
      break;
    }
  }
  if(flag2==1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
