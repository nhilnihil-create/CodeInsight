#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int n,m,r;
  cin >> n >> m >> r;
  vint R(r);
  rep(i,0,r){
    int r;
    cin >> R[i];
    R[i]--;
  }
  vvint to(n,vint(n,INF));
  rep(i,0,n){
    to[i][i] = 0;
  }
  rep(i,0,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    to[a][b] = c;
    to[b][a] = c;
  }
  rep(i,0,n){
    rep(j,0,n){
      rep(s,0,n){
        to[j][s] = min(to[j][s],to[j][i] + to[i][s]);
      }    
    }
  }
  sort(R.begin(),R.end());
  int ans = INF;
  do{
    int tmp = 0;
    rep(i,0,r-1){
      tmp += to[R[i]][R[i+1]];
    }
    ans = min(ans,tmp);
  }while(next_permutation(R.begin(),R.end()));
  cout << ans << endl;
}