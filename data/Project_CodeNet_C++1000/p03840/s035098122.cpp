#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e10;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 
#define int long long
#define double long double



////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////i

int a[10], ans1, ans2;
signed main(){
  rep(i,7)cin>>a[i];
  ans1 = ans2 = a[1];
  ans1 += (a[0]/2)*2;
  ans1 += (a[3]/2)*2;
  ans1 += (a[4]/2)*2;

  if(a[0] && a[3] && a[4]){
    ans2 += 3;a[0]--;a[3]--;a[4]--;
  }
  ans2 += (a[0]/2)*2;
  ans2 += (a[3]/2)*2;
  ans2 += (a[4]/2)*2;
  cout << max(ans1, ans2) << endl;
}



