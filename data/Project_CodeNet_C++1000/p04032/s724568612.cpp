#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
// int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<int>>vec(n+1,vector<int>(26,0));
  rep(i,n){
    rep(j,26){
      int add=0;
      if(s[i]-'a'==j)add++;
      vec[i+1][j]+=vec[i][j]+add;
    }
  }
  int l=-1,r=-1;
  if(n == 2){
    if(s[0]==s[1]){
      l=1;
      r=2;
    }
  }
  else{
    for(int i=0;i+3<=n;i++){
      rep(j,26){
        if(vec[i+3][j]-vec[i][j]>=2){
          l=i+1;
          r=i+3;
          break;
        }
      }
      if(l>0 && r>0)break;
    }
  }
  
  cout << l << " " << r << endl;
  return 0;
}
