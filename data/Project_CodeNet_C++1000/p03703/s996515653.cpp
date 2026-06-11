#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

//const value
//const ll MOD = 1e9 + 7;
//const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
//const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

#define MAX_N 200010
ll bit[MAX_N + 1], n;

ll sum(int i){
  ll s = 0;
  while(i > 0){
    s += bit[i]; // s += bit[i];
    i -= i & -i; // xの下のビットをみる
  }
  return s;
}

void add(int i,ll x){
  // 親に更新伝えて行く
  while(i <= n){
    bit[i] += x;
    i += i & -i; // xのもっとも下の立っている最も下のビット
  }
}

void cocomp(VLL &v){
    VLL p(v);
    sort(all(p));
    map<ll,ll> mp;
    ll cnt = 1;
    int n = v.size();
    rep(i,n){
        if(mp[p[i]] != 0){
            continue;
        }else{
            mp[p[i]] = cnt;
            cnt++;
        }
    }
    rep(i,n){
        v[i] = mp[v[i]];
    }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll k;
  cin >> n >> k;
  VLL v(n);
  VLL a(n);

  rep(i,n) cin >> a[i];
  FOR(i,1,n) a[i] += a[i-1];

  rep(i,n) v[i] = a[i] - (k * i);

  cocomp(v);

  // rep(i,n+1) cout << v[i] << " ";
  // cout << endl;

  ll ans = 0;
  // l == 0 のとき
  rep(i,n) {
    if( a[i] >= k * (i+1) ) ans++;
  }

  rep(i,n){
    ans += sum(v[i]);
    add(v[i],1);
  }
  cout << ans << endl;
  return 0;
}
