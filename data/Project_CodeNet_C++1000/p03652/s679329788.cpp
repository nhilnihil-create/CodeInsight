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
  itn n,m; cin >> n >> m;
  vector<vector<int> > a(n,vector<int>(m));
  rep(i,n)rep(j,m){
    cin >> a[i][j];
    a[i][j]--;
  }
  set<int> erased;
  vector<set<int> > sp(m);
  map<int,int> it;
  set<itn> tg;
  rep(i,n) tg.insert(i);
  int ans=n;
  while(erased.size()<=m-1){
    for(auto i:tg){
      while(erased.count(a[i][it[i]])) it[i]++;
      sp[a[i][it[i]++]].insert(i);
    }
    tg.clear();
    int mx=0;
    rep(i,m) chmax(mx,(int)sp[i].size());
    rep(i,m){
      if(sp[i].size()==mx){
        for(auto v:sp[i]) tg.insert(v);
        erased.insert(i);
        sp[i].clear();
      }
    }
    chmin(ans,mx);
  }
  cout << ans << endl;
}