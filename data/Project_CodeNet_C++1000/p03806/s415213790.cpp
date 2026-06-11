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

  int n,ma,mb;
  cin>>n>>ma>>mb;

  vector<int> p(n);
  vector<int> q(n);
  vector<int> r(n);
  rep(i,n){
    cin>>p[i]>>q[i]>>r[i];
  }

  int ans=100100100;

  if(ma==1&&mb==1){
  //——————————————bit全探索——————————————
  map<int,int> m;
  repo(i, (1<<min(n,20))){
    int asum=0;
    int bsum=0;
    int csum=0;
    rep(j,min(n,20)){
      if(i & (1<<j)){
        asum+=p[j];
        bsum+=q[j];
        csum+=r[j];
      }
    }
    if(bsum==asum) chmin(ans,csum);
    int z=asum-bsum;
    if(m.count(z)) chmin(m.at(z),csum);
    else m[z]=csum;
  }

  //——————————————————————————————————————

  if(n<=20) {
    if(ans==100100100) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
  }

  //——————————————bit全探索——————————————
  int nn=n-20;
  repo(i, (1<<nn)){
    int asum=0;
    int bsum=0;
    int csum=0;
    rep(j,nn){
      if(i & (1<<j)){
        asum+=p[20+j];
        bsum+=q[20+j];
        csum+=r[20+j];
      }
    }
    if(bsum==asum) chmin(ans,csum);
    int z=bsum-asum; 
    if(m.count(z)) chmin(ans,csum+m.at(z));
  }

  //——————————————————————————————————————

  if(ans==100100100) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
  }



  //——————————————bit全探索——————————————
  map<pair<int,int>,int> m;
  repo(i, (1<<min(n,20))){
    int asum=0;
    int bsum=0;
    int csum=0;
    rep(j,min(n,20)){
      if(i & (1<<j)){
        asum+=p[j];
        bsum+=q[j];
        csum+=r[j];
      }
    }
    if(ma*bsum==mb*asum) chmin(ans,csum);
    pair<int,int> z={asum,bsum};
    if(m.count(z)) chmin(m.at(z),csum);
    else m[z]=csum;
  }

  //——————————————————————————————————————


  if(n<=20) {
    if(ans==100100100) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
  }

  //——————————————bit全探索——————————————
  int nn=n-20;
  repo(i, (1<<nn)){
    int asum=0;
    int bsum=0;
    int csum=0;
    rep(j,nn){
      if(i & (1<<j)){
        asum+=p[20+j];
        bsum+=q[20+j];
        csum+=r[20+j];
      }
    }
    if(ma*bsum==mb*asum) chmin(ans,csum);
    repo(j,500){
      int x=ma*j;
      if(x<asum) continue;
      if(x-asum>200) break;
      int y=mb*j;
      if(y<bsum) continue;
      if(y-bsum>200) break;
      pair<int,int> z={x-asum,y-bsum};
      if(m.count(z)) chmin(ans,csum+m.at(z));
    }
  }

  //——————————————————————————————————————

  if(ans==100100100) cout << -1 << endl;
  else cout << ans << endl;
}