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
  
  int n;
  cin >> n;
  vector<int>a(n);
  rep(i,n) cin >> a[i];
  
  int sum =0;
  rep(i,n) sum+=a[i];
  sum/=n;
  
  ll res1 = 0;
  rep(i,n) res1+=pow(sum-a[i],2);
  sum++;
  ll res2 = 0;
  rep(i,n) res2+=pow(sum-a[i],2);
  
  cout << min(res1,res2) << endl;
  return 0;
}
