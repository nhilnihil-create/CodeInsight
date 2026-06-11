#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define rrep(i,n) for (int i = n-1; i >= 0; i--)
#define MOD (1000000007)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back

#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll keta(ll n){
  string s = to_string(n);
  ll num = s.size();
  return num;
}

const ll INF = 1LL << 60;

const int dh[4] = {1,0,-1,0};
const int dw[4] = {0,1,0,-1};

struct Edge{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w){}
};
using Graph = vector<vector<Edge>>;
using P = pair<ll, int>;

const int MAX = 5100000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  int H,W; cin >> H >> W;
  vector<string> a(H);
  rep(h,H) cin >> a[h];
  int cnt_4 = (H/2)*(W/2);
  int cnt_2,cnt_1;
  if((H*W)%2 == 1) cnt_1 = 1;
  else cnt_1 = 0;
  cnt_2 = (H*W - cnt_4*4 - cnt_1)/2;
  //printf("%d %d %d\n", cnt_4,cnt_2,cnt_1);

  map<char,int> C;
  rep(h,H) rep(w,W) C[a[h][w]]++;
  vi v;
  for(auto c : C) {
    int num = c.second;
    v.pb(num);
  }

  for(auto i : v) {
    while(i-4 >= 0 && cnt_4 > 0){
      i -= 4;
      cnt_4--;
    }
    while(i-2 >= 0 && cnt_2 > 0){
      i -= 2;
      cnt_2--;
    }
    while(i-1 >= 0 && cnt_1 > 0){
      i -= 1;
      cnt_1--;
    }
  }

  if(cnt_1 == 0 && cnt_2 == 0 && cnt_4 == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}
