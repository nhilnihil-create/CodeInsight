#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define e_b emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())

#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)

#ifdef LOCAL//compile with -DLOCAL
#define debug(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = "<<(x)<<endl
#define debug_vec(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = ";\
  rep(i,sz(x)){cerr<<x[i]<<" ";}cerr<<endl
#define debug_mat(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = "<<endl;\
  rep(i,sz(x)){rep(j,sz(x[i])){cerr<<x[i][j]<<" ";}cerr<<endl;}cerr<<endl
#else
#define debug(x) void(0)
#define debug_vec(x) void(0)
#define debug_mat(x) void(0)
#endif

template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}


int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N,A,B;
  cin >> N >> A >> B;
  vector<int> a(N),b(N),c(N);
  rep(i,N)  cin >> a.at(i) >> b.at(i) >> c.at(i);

  vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(500,vector<int>(500,5000)));
  dp.at(0).at(0).at(0)=0;
  rep(i,N){
    rep(j,500){
      rep(k,500){
        chmin(dp.at(i+1).at(j).at(k),dp.at(i).at(j).at(k));
        if(j+a.at(i)<500 && k+b.at(i)<500){
          chmin(dp.at(i+1).at(j+a.at(i)).at(k+b.at(i)),dp.at(i).at(j).at(k) + c.at(i));
        }
      }
    }
  }
  int ans=5000;
  REP(i,1,500){
    if(i*A>=500 || i*B>=500)  break;
    chmin(ans,dp.at(N).at(i*A).at(i*B));
  }
  if(ans==5000) ans=-1;
  cout << ans << endl;

  return 0;
}