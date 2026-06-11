#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define lb(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define ub(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
using Pair = pair<ll,pair<int,int>>;
#define pq priority_queue<Pair, vector<Pair>, greater<Pair>> 
const ll mod=1000000007;
//const ll mod=998244353;
const ld pi=acos(-1.0);
const ll INF = 1LL<<61;
template<class T>bool chmax(T &a, const T &b) { 
  if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) {
  if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m;
  cin>>n>>m;

  vector<pair<pair<int,int>,ll>> p(m);
  rep(i,m){
    ll a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    p[i]={{a,b},-c};
  }

  vector<ll> d(n,INF);
  d[0]=0;
  rep(i,n-1){
    rep(j,m){
      if(d[p[j].fi.fi]==INF) continue;
      chmin(d[p[j].fi.se],d[p[j].fi.fi]+p[j].se);
    }
  }

  ll ans=d[n-1];

  vector<bool> neg(n,false);
  rep(i,n){
    rep(j,m){
      int a=p[j].fi.fi;
      int b=p[j].fi.se;
      ll c=p[j].se;
      if(d[a]==INF) continue;
      if(chmin(d[b],d[a]+c)){
        neg[b]=true;
      }
      if(neg[a]) neg[b]=true;
    }
  }


  if(neg[n-1]) cout << "inf" << endl;
  else cout << -ans << endl;
  return 0;

}