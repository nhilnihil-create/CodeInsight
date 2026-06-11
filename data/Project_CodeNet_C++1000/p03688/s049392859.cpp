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

int n,a[110000];
signed main(){
  cin>>n;int mx = -1, mm = INF;
  rep(i,n){
    cin>>a[i];
    chmax(mx, a[i]);chmin(mm, a[i]);
  }
  if(mx - mm >= 2){
    cout << "No" << endl;
  }else if(mx == mm){
    if(mx == n-1 || n >= 2*mx)cout << "Yes" << endl;
    else cout << "No" << endl;
  }else{
    int cntx = 0, cntm = 0;
    rep(i,n)(a[i] == mx ? cntx : cntm)++;
    if(cntx >= 2 && cntx >= 2*(mx-cntm) && mx-cntm > 0){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
  
}
