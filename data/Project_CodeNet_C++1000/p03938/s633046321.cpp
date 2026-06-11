#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b) {if(a>b) {a=b; return true;} return false;}
#define itn int
#define fi first
#define se second
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
const int inf=2e9;
const ll lnf=9e18;

int main(){
  int n; cin >> n;
  vector<int> q(n);
  vector<int> p(n);
  rep(i,n){
    cin >> q[i];
    q[i]--;
  }
  rep(i,n) p[q[i]]=i;
  vector<int> a(n);
  vector<int> b(n);
  rep(i,n) a[i]=i+1;
  rep(i,n) b[i]=n-i;
  vector<int> lazya=p;
  vector<int> lazyb=p;
  rep(i,n-1) lazya[i+1]+=lazya[i];
  for(itn i=n-1;i>0;i--) lazyb[i-1]+=lazyb[i];
  rep(i,n){
    a[i]+=lazya[i];
    b[i]+=lazyb[i];
  }
  rep(i,n){
    cout << a[i] << " ";
  }cout << endl;
  rep(i,n){
    cout << b[i] << " ";
  }cout << endl;
}