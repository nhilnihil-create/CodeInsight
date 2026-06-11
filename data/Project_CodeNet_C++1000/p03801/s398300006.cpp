#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

bool compP(pair<ll, ll> a, pair<ll, ll> b){

  if(a.first != b.first){
    return a.first > b.first;
  }else{
    return a.second > b.second;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<pair<ll, ll>> vec(N);

  ll a;
  rep(i, N){
    cin >> a;
    vec[i] = make_pair(a, i+1);
  }
  vec.push_back(make_pair(0, 0));

  sort(vec.begin(), vec.end(), compP);

  vector<ll> ans(N+1);

  ll pre_max = vec[0].first;
  ll pre_ind = vec[0].second;
  ll cnt = 0;
  ll sum_kouho = pre_max;
  ll cnt_kouho = 1;

  for(int i = 1; i <= N; i++){

    if(vec[i].first <= pre_max && vec[i].second < pre_ind){

      ans[pre_ind] = cnt * (pre_max - vec[i].first) + sum_kouho - vec[i].first * cnt_kouho;
      cnt += cnt_kouho;
      sum_kouho = vec[i].first;
      cnt_kouho = 1;
      pre_ind = vec[i].second;
      pre_max = vec[i].first;

    }else{

      cnt_kouho++;
      sum_kouho += vec[i].first;

    }

  }

  for(int i = 1; i <= N; i++){

    cout << ans[i] << endl;

  }

  return 0;
}
