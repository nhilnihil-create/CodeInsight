#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 
#define int long long
#define double long double

////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////

int n,k,a[20];
signed main(){
  cin>>n>>k;rep(i,n)cin>>a[i];
  int ans = INF;
  rep(bit, 1<<n){
    int cnt = 0, sum = 0, max = 0;
    rep(i,n)if(bit&(1<<i))cnt++;
    if(cnt != k)continue;
    rep(i,n){
      if(bit&(1<<i)){
        if(max < a[i]){
          max = a[i];
        }else{
          max++;
          sum += max - a[i];
        }
      }else{
        chmax(max, a[i]);
      }
    }
    chmin(ans, sum);
  }
  cout << ans << endl;
}


