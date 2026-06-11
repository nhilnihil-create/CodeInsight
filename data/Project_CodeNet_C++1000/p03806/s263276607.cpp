#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
#define fix10 cout << fixed << setprecision(10);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007
#define INF 1e9

int main(){
  int n,ma,mb;
  cin >> n >> ma >> mb;
  vector<vvi> dp(n+1,vvi(401,vi(401,INF)));
  dp.at(0).at(0).at(0) = 0;
  rep(k,n){
    int a,b,c;
    cin >> a >> b >> c;
    rep(i,401){
      rep(j,401){
        if(i-a >= 0 && j-b >= 0){
          dp.at(k+1).at(i).at(j) = min(dp.at(k).at(i).at(j),dp.at(k).at(i-a).at(j-b) + c);
        }else{
          dp.at(k+1).at(i).at(j) = dp.at(k).at(i).at(j);
        }
      }
    }
  }
  int id = 1;
  int ans = INF;
  while(ma*id < 401 && mb*id < 401){
    //cout << ans << endl;
    ans = min(ans,dp.at(n).at(ma*id).at(mb*id));
    id++;
  }
  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
}