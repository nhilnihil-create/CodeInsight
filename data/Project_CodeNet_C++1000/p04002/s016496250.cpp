#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define pi acos(-1.0)
const ll INF = 1LL<<61;
template<class T>bool chmax(T &a, const T &b) { 
  if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) {
  if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll jou(ll N, ll P){if(P==0) return 1;
  if(P%2==0){ll t = jou(N, P/2);return t*t % mod;
  }return (N * jou(N, P-1)) % mod;}  //jou(n,mod-2)で逆元
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる


int black(ll x, ll y, set<pair<ll,ll>> &q){
  int cnt=0;
  rep(i,3){
    rep(j,3){
      auto z=mp(x+i,y+j);
      if(q.count(z)) cnt++;
    }
  }
  return cnt;
}


int main(){
  ll h,w,n;
  cin>>h>>w>>n;

  vector<ll> p(10);
  p[0]=(h-2)*(w-2);

  set<pair<ll,ll>> q;
  rep(i,n){
    ll a,b;
    cin>>a>>b;
    a--;b--;
    auto z=mp(a,b);
    
    if(a-2>=0&&b-2>=0) {
      int c=black(a-2,b-2,q);
      p[c]--;p[c+1]++;
    }
    if(a-1>=0&&a+1<h&&b-2>=0) {
      int c=black(a-1,b-2,q);
      p[c]--;p[c+1]++;
    }
    if(a+2<h&&b-2>=0) {
      int c=black(a,b-2,q);
      p[c]--;p[c+1]++;
    }

    if(a-2>=0&&b-1>=0&&b+1<w) {
      int c=black(a-2,b-1,q);
      p[c]--;p[c+1]++;
    }
    if(a-1>=0&&a+1<h&&b-1>=0&&b+1<w) {
      int c=black(a-1,b-1,q);
      p[c]--;p[c+1]++;
    }
    if(a+2<h&&b-1>=0&&b+1<w) {
      int c=black(a,b-1,q);
      p[c]--;p[c+1]++;
    }

    if(a-2>=0&&b+2<w) {
      int c=black(a-2,b,q);
      p[c]--;p[c+1]++;
    }
    if(a-1>=0&&a+1<h&&b+2<w) {
      int c=black(a-1,b,q);
      p[c]--;p[c+1]++;
    }
    if(a+2<h&&b+2<w) {
      int c=black(a,b,q);
      p[c]--;p[c+1]++;
    }

    q.insert(z);
  }

  rep(i,10){
    cout << p[i] << endl;
  }

}