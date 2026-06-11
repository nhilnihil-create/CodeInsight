#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 


////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////

int n,ma,mb,a[50],b[50],c[50];
vector<P> v, u;
signed main(){
  cin>>n>>ma>>mb;rep(i,n)cin>>a[i]>>b[i]>>c[i];
  int m = n/2;n -= m;
  rep(i,1<<n){
    int aa = 0, bb = 0, cc = 0;
    rep(j,n){
      if(i&(1<<j)){
        aa += a[j];bb += b[j];cc += c[j];
      }
    }
    v.push_back(P(aa*mb-bb*ma, cc));
  }
  rep(i,1<<m){
    int aa = 0, bb = 0, cc = 0;
    rep(j,m){
      if(i&(1<<j)){
        aa += a[n+j];bb += b[n+j];cc += c[n+j];
      }
    }
    u.push_back(P((bb*ma-aa*mb), cc));
  }
  int ans = INF;sort(u.begin(), u.end());

  rep(i,v.size()){
    auto itr = lower_bound(u.begin(), u.end(), P(v[i].first, (v[i].second == 0 ? 1 : 0)));
    if(itr == u.end())continue;
    if((*itr).first == v[i].first)chmin(ans, v[i].second + (*itr).second);
  }
  cout << (ans == INF ? -1 : ans) << endl;
}
