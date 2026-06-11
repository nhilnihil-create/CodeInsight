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

  int n;
  ll z;
  cin>>n>>z;

  vector<ll> w(n);
  vector<ll> v(n);
  rep(i,n){
    cin>>w[i]>>v[i];
  }

  vector<ll> v0;
  vector<ll> v1;
  vector<ll> v2;
  vector<ll> v3;
  rep(i,n){
    if(w[i]==w[0]) v0.pb(v[i]);
    if(w[i]==w[0]+1) v1.pb(v[i]);
    if(w[i]==w[0]+2) v2.pb(v[i]);
    if(w[i]==w[0]+3) v3.pb(v[i]);
  }

  int s0=v0.size();
  int s1=v1.size();
  int s2=v2.size();
  int s3=v3.size();

  sort(all(v0));
  reverse(all(v0));
  sort(all(v1));
  reverse(all(v1));
  sort(all(v2));
  reverse(all(v2));
  sort(all(v3));
  reverse(all(v3));

  repo(i,s0) v0[i]+=v0[i-1];
  repo(i,s1) v1[i]+=v1[i-1];
  repo(i,s2) v2[i]+=v2[i-1];
  repo(i,s3) v3[i]+=v3[i-1];

  ll ans=0;
  rep(i,s0+1){
    rep(j,s1+1){
      rep(k,s2+1){
        rep(l,s3+1){
          if(i+j+k+l>n) continue;
          if(i*w[0]+j*(w[0]+1)+k*(w[0]+2)+l*(w[0]+3)>z) continue;
          ll g0=0,g1=0,g2=0,g3=0,sum=0;
          if(i!=0) g0=v0[i-1];
          if(j!=0) g1=v1[j-1];
          if(k!=0) g2=v2[k-1];
          if(l!=0) g3=v3[l-1];
          sum=g0+g1+g2+g3;
          chmax(ans,sum);
        }
      }
    }
  }


  cout << ans << endl;
}