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

int n,a,b,v[55];

int c[51][51];
void cominit(){
  rep(i,51){
    rep(j,i+1){
      if(j == 0 || j == i){
        c[i][j] = 1LL;
      }else{
        c[i][j] = (c[i-1][j-1] + c[i-1][j]);
      }
    }
  }
}

signed main(){
  cin>>n>>a>>b;rep(i,n)cin>>v[i];
  sort(v,v+n,greater<int>());
  double sum = 0, ave = 0;
  rep(i,n){
    sum += v[i];
    if(i+1 < a || b < i+1)continue;
    chmax(ave, sum/(i+1));
  }
  cominit();
  map<int, int> mp;
  rep(i,n)mp[v[i]]++;
  int ans = 0;sum = 0;
  rep(i,n){
    sum += v[i];
    if(i+1 < a || b < i+1)continue;
    if(sum/(i+1) == ave){
      map<int,int> cmp;int k = 1;
      rep(j,i+1)cmp[v[j]]++;
      rep(j,i+1){
        if(j > 0 && v[j-1] == v[j])continue;
        k *= c[mp[v[j]]][cmp[v[j]]];
      };
      ans += k;
    }
  }
  cout << fixed << ave << endl;
  cout << ans << endl;
}
