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
const ll INF = 1e10;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 




////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////

int n,a,b,c,d;
signed main(){
  cin>>n>>a>>b>>c>>d;
  if(a > b)swap(a,b);
  a = b-a;
  rep(i,n){
    int upmax = d*i, upmin = c*i, dnmax = (-d)*(n-i-1), dnmin = (-c)*(n-i-1);
    if(upmin + dnmax <= a && a <= upmax + dnmin){
      cout << "YES" << endl;return 0;
    }
  }
  cout << "NO" << endl;
}
