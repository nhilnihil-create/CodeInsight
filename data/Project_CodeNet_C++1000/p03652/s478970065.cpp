#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  int A[N][M];
  REP(i,N)REP(j,M){
    cin>>A[i][j];
    A[i][j]--;
  }
  int ans=N;
  int S[M];
  REP(i,M)S[i]=1;
  REP(m,M){
    int T[M];
    REP(i,M)T[i]=0;
    REP(i,N){
      REP(j,M)if(S[A[i][j]]){
        T[A[i][j]]++;
        break;
      }
    }
    int argmax_t=distance(T,max_element(T,T+M));
    ans=min(ans,T[argmax_t]);
    S[argmax_t]=0;
    // REP(i,M)cerr<<T[i];
    // cerr<<endl;
    // cerr<<argmax_t<<endl;
    // REP(i,M)cerr<<S[i];
    // cerr<<endl;
  }
  cout<<ans<<endl;
  return 0;
}
