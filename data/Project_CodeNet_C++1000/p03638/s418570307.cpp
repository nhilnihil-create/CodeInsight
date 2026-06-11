#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> rec;
  rep(i,n){
    rep(j,a[i]) rec.pb(i+1);
  }
  bool r = false;
  for (int i = 0; i < h * w; i += w) {
    //printf("i is %d\n", i);
    vector<int> tmp;
    for (int j = i; j < i + w; j++) tmp.pb(rec[j]);
    if (r) reverse(all(tmp));
    r = !r;
    rep(j,sz(tmp)) cout << tmp[j] << " ";
    cout  << endl;
  }
  return 0;
}
