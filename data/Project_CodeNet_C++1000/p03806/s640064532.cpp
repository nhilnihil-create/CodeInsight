#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<deque>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#include<iomanip>
#include<cassert>
#include<regex>
#include<bitset>
#include<complex>
#include<chrono>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
using namespace std;

int dp[45][500][500];
void solve(){
  int n,ma,mb;
  cin>>n>>ma>>mb;
  const int infty=1e5;
  rep(i,45){
    rep(j,500){
      rep(k,500)dp[i][j][k]=infty;
    }
  }
  dp[0][0][0]=0;
  vector<int>a(n),b(n),c(n);
  rep(i,n)cin>>a[i]>>b[i]>>c[i];
  rep(i,n){
    rep(j,401){
      rep(k,401){
        if(j-a[i]>=0&&k-b[i]>=0)chmin(dp[i+1][j][k],dp[i][j-a[i]][k-b[i]]+c[i]);
        chmin(dp[i+1][j][k],dp[i][j][k]);
      }
    }
  }
  int ans=infty;
  for(int i=1;;++i){
    if(ma*i>400||mb*i>400)break;
    chmin(ans,dp[n][ma*i][mb*i]);
  }
  if(ans==infty)cout<<-1;
  else cout<<ans;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}
