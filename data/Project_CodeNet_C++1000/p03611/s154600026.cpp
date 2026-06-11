#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);++i)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
 
const int MAX=510000;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  int n;
  cin >> n;
  vector<int>a(n);
  rep(i,n) cin >> a[i];
  int ans = 1;
  vector<int>num(100010);
  rep(i,n){
    num[a[i]]++;
    num[a[i]+1]++;
    num[a[i]+2]++;
  }
  rep(i,(int)num.size()){
    chmax(ans,num[i]);
  }
  cout << ans << endl;
    
  return 0;
}
