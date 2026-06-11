//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
#define endn "\n"
typedef pair<int,int> P;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
const string abc="abcdefghijklmnopqrstuvwxyz";
const string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 


////////////////////////////////////////////////////////////////////

int n,m;int t[110000], c[110000], d[110000];
signed main(){
  cin>>n>>m;
  rep(i,n){
    int x;cin>>x;
    c[x%m]++;
    t[x]++;
    if(t[x]%2 == 0)d[x%m]++;//同じ数の2枚組を数える
  }
  int ans = 0;
  rep(md,m){
    if(c[md] == -1)break;
    int op = (m-md)%m;
    if(md == op){
      ans += c[md]/2;
      c[md] = -1;
    }else{
      int dc = min(c[md], c[op]);
      ans += dc;
      c[md] -= dc;
      c[op] -= dc;
      ans += max(min(d[op], c[op]/2), min(d[md], c[md]/2));
      c[md] = c[op] = -1;
    }
  }
  cout << ans << endl;
}
