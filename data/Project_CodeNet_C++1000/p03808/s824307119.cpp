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
  vector<ll> a(n);
  ll sum=0;
  rep(i,n){
    cin >> a[i];
    sum+=a[i];
  }
  if(sum%(n*(n+1)/2)){
    cout << "NO" << endl;
    return 0;
  }
  ll sousa=sum/(n*(n+1)/2);
  vector<ll> tol(n);
  rep(i,n) tol[i]=a[i]-a[(i-1+n)%n]-sousa;
  rep(i,n){
    if(tol[i]%n||tol[i]>0){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}