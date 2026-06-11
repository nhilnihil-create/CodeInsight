#ifdef __LOCAL
  #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b) {if(a>b) {a=b; return true;} return false;}
#define itn int
#define fi first
#define se second
#define intmax numeric_limits<int>::max()
#define llmax numeric_limits<ll>::max()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sortt(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;
const ll lnf=1ll<<60;

int main(){
  ll n; cin >> n;
  if(n==1){
    cout << "YES" << endl;
    return 0;
  }
  vector<int> a(n);
  ll sum=0;
  rep(i,n){
    cin >> a[i];
    sum+=a[i];
  }
  vector<itn> tol(n);
  rep(i,n) tol[i]=a[i]-a[(i-1+n)%n];
  int mx=0;
  rep(i,n) chmax(mx,tol[i]);
  ll cnt=0;
  rep(i,n){
    if((mx-tol[i])%n){
      cout << "NO" << endl;
      return 0;
    }
    cnt+=(mx-tol[i])/n;
  }
  if(sum==n*(n+1)/2*cnt) cout << "YES" << endl;
  else cout << "NO" << endl;
}