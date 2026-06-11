#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
//typedef pair<ll, ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define revrep(i, n) for(ll i = (n)-1; i >= 0; i--)
#define pb push_back
#define f first
#define s second
/*
ll max(ll a, ll b){return (a > b) ? a : b;}
ll min(ll a, ll b){return (a < b) ? a : b;}
ll max3(ll a, ll b, ll c){return max(a, max(b, c));};
ll min3(ll a, ll b, ll c){return min(a, min(b, c));};
ll max4(ll a, ll b, ll c, ll d){return max(max(a, b), min(c, d));};
ll min4(ll a, ll b, ll c, ll d){return min(min(a, b), min(c, d));};
ll max5(ll a, ll b, ll c, ll d, ll e){return max(max(a, b), max3(c, d, e));};
ll min5(ll a, ll b, ll c, ll d, ll e){return min(min(a, b), min3(c, d, e));};
*/
const ll INFL = 1LL << 60;//10^18 = 2^60
const int INF = 1 << 30;//10^9
//ll MOD = 1000000007;
ll MOD = 998244353;

vector<ll> dy = {0, 0, 1, -1, 1, 1, -1, -1, 0};
vector<ll> dx = {1, -1, 0, 0, 1, -1, 1, -1, 0};

//デバッグ
void BinarySay(ll x, ll y = 60){rep(i, y) cout << (x>>(y-1-i) & 1); cout << endl;}

ll pow_long(ll x, ll k){
  ll res = 1;
  while(k > 0){
    if(k % 2) res *= x;
    x *= x;
    k /= 2;
  }
  return res;
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll x, ll y){return x / gcd(x, y) * y;};

bool need(vector<ll> A, vector<ll> B, set<ll> X){//xの要素のみでA->Bが全て実現可能か
  ll dist[51][51];
  rep(i, 51)rep(j, 51) dist[i][j] = 1;
  rep(i, 51) dist[i][i] = 0;
  for(ll i = 0; i < 51; i++){
    for(auto itr = X.begin(); itr != X.end(); itr++){
      dist[i][i%(*itr)] = 0;
    }
  }
  rep(k, 51)rep(i, 51)rep(j, 51) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  rep(i, A.size()){
    if(dist[A[i]][B[i]] != 0) return 0;
  }
  return 1;
}

ll sub(vector<ll> X){
  ll sum = 0;
  ll M = 0;
  rep(i, X.size()){
    sum += X[i];
    M = max(M, X[i]);
  }
  if(M > (sum - M)){
    return 2 * M - sum;
  }else{
    return sum % 2;
  }
}

ll N;
vector<ll> A;
vector<ll> E[100010];

ll dfs(ll now, ll from){
  vector<ll> xs;
  ll M = 0;
  for(ll to : E[now]){
    if(to == from) continue;
    xs.pb(dfs(to, now));
    M += xs.back();
    if(xs.back() == -1) return -1;
  }
  if(xs.size() == 0) return A[now];
  ll m = sub(xs);
  ll M_loop = (M - m) / 2;
  if(A[now] < m + M_loop || A[now] > M) return -1;
  return 2 * A[now] - M;
}

int main(){
  cin >> N;
  A.resize(N);
  rep(i, N) cin >> A[i];
  rep(i, N-1){
    ll a, b;
    cin >> a >> b;
    a--, b--;
    E[a].pb(b);
    E[b].pb(a);
  }
  if(N == 2){
    if(A[0] == A[1]){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
    return 0;
  }
  ll x = -1;
  rep(i, N){
    if(E[i].size() != 1) x = i;
  }
  if(dfs(x, -1) == 0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
