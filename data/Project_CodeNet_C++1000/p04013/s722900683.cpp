#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
constexpr int di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define all(v) (v).begin(), (v).end()
#define vmax 10000
constexpr ll inf = 1e18+7;
/*cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);*/
ll n,a,ans=0;
ll dp[53][53][2503];

int main(){
  cin>>n>>a;
  vector<int> x(n);
  rep(i,n){
    cin>>x[i];
  }
  rep(i,2501){
    dp[0][0][i]=0;
  }

  dp[0][0][0]=1;

  rep(i,n){
    rep(k,n){
      rep(j,2501){
      if(j-x[i]>=0){
        dp[i+1][k+1][j]+=dp[i][k][j-x[i]];
        dp[i+1][k][j]+=dp[i][k][j];
      }else{
        dp[i+1][k][j]+=dp[i][k][j];
      }
      }
    }
  }
  rep(k,n+1){
    rep(j,2501){
      if(j==k*a){
        ans+=dp[n][k][j];
      }
    }
  }
  cout<<ans-1<<endl;
  return 0;
}
