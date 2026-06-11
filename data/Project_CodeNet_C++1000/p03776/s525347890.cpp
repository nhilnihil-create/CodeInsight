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

//—————————————————————————————————————————————————

ll com(ll n, ll k){
	if(n<k) return 0;
	if(k==0) return 1;
	ld r = 1;
	for(ld i=0;i<k;++i){
		r = r*(ld)(n-i)/(ld)(k-i);
	}
  ll re=r;
	if(abs(re-r)<0.01) return re;
  re++;
  if(abs(re-r)<0.01) return re;
  return re-2;
}

//—————————————————————————————————————————————————

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);


  int n,a,b;
  cin>>n>>a>>b;

  vector<ld> p(n);
  rep(i,n){
    cin>>p[i];
  }

  sort(all(p));
  reverse(all(p));

  ld sum=0;
  rep(i,a){
    sum+=p[i];
  }
  cout << fixed << setprecision (20);   
  cout << sum/a << endl;

  int sa=0;
  int di=0;
  rep(i,n){
    if(p[i]==p[a-1]) sa++;
  }
  rep(i,a){
    if(p[i]!=p[a-1]) di++;
  }

  if(p[0]!=p[a-1]){
    cout << com(sa,a-di) << endl;
  }
  else {
    ll ans=0;
    for(int i=a-di;i<=b-di;i++){
      ans+=com(sa,i);
    }
    cout << ans << endl;
  }

}