#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int n,m,r;
  cin >> n >> m >> r;
  ll dist[n][n];
  rep(i,n)rep(j,n)dist[i][j]=1e9;
  
  vector<int>city(r);
  rep(i,r){
    cin >> city[i];
    city[i]--;
  }
  sort(city.begin(),city.end());
  rep(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--;
    b--;
    dist[a][b]=c;
    dist[b][a]=c;
  }
  rep(k,n){
    rep(i,n){
      rep(j,n){
        chmin(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }
  ll ans = INF;
  do{
    ll res = 0;
    rep(i,r-1){
      res+=dist[city[i]][city[i+1]];
    }
    chmin(ans,res);
  }while(next_permutation(city.begin(),city.end()));
  
  cout << ans << endl;
  return 0;
}
