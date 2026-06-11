#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define itn int
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sort(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=2e9;
const ll lnf=9e18;

ll kiri(ll a,ll b){return a%b==0?a/b:a/b+1;}

int main(){
  itn n; cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i,n) cin >> a[i] >> b[i];
  rep(i,n-1){
    if(a[i]<=a[i+1]&&b[i]<=b[i+1]) continue;
    ll mx=max(kiri(a[i],a[i+1]),kiri(b[i],b[i+1]));
    a[i+1]=a[i+1]*mx;
    b[i+1]=b[i+1]*mx;
  }
  cout << a[n-1]+b[n-1] << endl;
}