#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

int nxt[200005][26];
int dp[200005];
pair<char,int> r[200005];

int main(){
  string A;
  cin >> A;

  int N = A.size();
  
  rep(i,26){
    nxt[N][i] = N;
  }

  for(int i=N-1; i>=0; i--){
    rep(j,26){
      nxt[i][j] = nxt[i+1][j];
      if(A[i] == 'a'+j){
        nxt[i][j] = i;
      }
    }
  }

  dp[N] = 1;
  for(int i=N-1; i>=0; i--){
    dp[i] = N+1;
    rep(j,26){
      if(nxt[i][j] == N){
        if(dp[i] > 1){
          dp[i] = 1;
          r[i] = make_pair('a'+j,N);
        }
      }else{
        if(dp[i] > dp[nxt[i][j]+1] + 1){
          dp[i] = dp[nxt[i][j]+1] + 1;
          r[i] = make_pair('a'+j,nxt[i][j]+1);
        }
      }
    }
  }

  string ret;
  int idx = 0;
  while(idx < N){
    ret += r[idx].first;
    idx = r[idx].second;
  }

  cout << ret << endl;
  
  return 0;
}
