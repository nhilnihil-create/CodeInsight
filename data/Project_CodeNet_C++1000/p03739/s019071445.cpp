#include <bits/stdc++.h>
using namespace std;
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
 
const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;
 
const int MAX = 1000000;
const int MOD = 1000000007;
 
int main(){
  int n;
  cin >> n;
  vector<ll>a(n);
  ll sum1 = 0,sum2 = 0, ans1 = 0, ans2 = 0;
  rep(i, 0, n)cin >> a[i];
  rep(i, 0, n){
    //sum1 += a[i];
    if(i%2==0){
      if(sum1+a[i]>0){
        sum1 += a[i];
        continue;
      }
      sum1 += a[i];
      ans1 += abs(1-sum1);
      sum1 = 1;
    }else{
      if(sum1+a[i]<0){
        sum1 += a[i];
        continue;
      }
      sum1 += a[i];
      ans1 += abs(-1-sum1);
      sum1 = -1;
    }
  }
  rep(i, 0, n){
    //sum2 += a[i];
    if(i%2==1){
      if(sum2+a[i]>0){
        sum2 += a[i];
        continue;
      }
      sum2 += a[i];
      ans2 += abs(1-sum2);
      sum2 = 1;
    }else{
      if(sum2+a[i]<0){
        sum2 += a[i];
        continue;
      }
      sum2 += a[i];
      ans2 += abs(-1-sum2);
      sum2 = -1;
    }
  }
  cout << min(ans1,ans2) << endl;
  //cout << ans1 << " " << ans2 << endl;
}