#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000

const int limit = 8;
vector<vbool> graph(limit,vbool(limit));
vbool visited(limit);

int dfs(int v,int n);

int main(){
  ll N,T;
  cin >> N >> T;
  vll A(N);
  ll X = 0;
  rep(i,N){
    cin >> A[i];
    X = max(X,A[i]);
  }
  ll ans = 0;
  ll dp[N+1][N+1][N*X+1];
  //i:何枚まで見ているか
  //j:そのうち何枚選ぶか
  //k:合計値はいくらか
  erep(j,N){
    erep(k,N*X){
      if(j == 0 && k == 0) dp[0][j][k] = 1;
      else dp[0][j][k] = 0;
    }
  }
  erep1(i,N){
    erep(j,N){
      erep(k,N*X){
        if(i > 0 && A[i-1] > k){
          dp[i][j][k] = dp[i-1][j][k];
        }
        else if(i > 0 && j > 0 && k - A[i-1] >= 0){
          dp[i][j][k] = dp[i-1][j-1][k-A[i-1]] + dp[i-1][j][k];
        }
        else{
           dp[i][j][k] = 0;
        }
      }
    }
  }
  /*erep(i,N){
    erep(j,N){
      erep(k,N*X){
        cout << dp[i][j][k];
      }
      cout << endl;
    }
    cout << endl;
  }*/
  erep(j,N){
    erep(k,N*X){
      if(k == j*T){
        ans += dp[N][j][k];
      }
    }
  }
  cout << ans-1 << endl;
}