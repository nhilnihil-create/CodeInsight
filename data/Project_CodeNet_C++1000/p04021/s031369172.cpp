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
int n;vector<int> a, b;

signed main(){
  cin>>n;int cnt = 0;
  rep(i,n){
    int aa;cin>>aa;
    a.push_back(aa);
    b.push_back(aa);
  }
  sort(b.begin(), b.end());
  rep(i,n){
    a[i] = distance(b.begin(), lower_bound(b.begin(), b.end(), a[i]));
    if(i%2 == 0 && a[i]%2 == 1)cnt++;
  }
  
  cout << cnt << endl;
}
