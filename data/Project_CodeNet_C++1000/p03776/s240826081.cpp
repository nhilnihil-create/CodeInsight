#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

std::vector<std::vector<long long>> comb(int n, int r) {
  std::vector<std::vector<long long>> v(n + 1,std::vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, A, B;
  cin >> N >> A >> B;
  vector<ll> v(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }

  sort(v.begin(), v.end(), greater<ll>());

  vector<vector<ll>> com = comb(50, 50);

  double max_avr = 0.0;
  for(int i = 0; i < A; i++){
    max_avr += v[i];
  }

  max_avr = max_avr / A;

  int p, q;
  p = 0;
  q = 0;
  for(int i = 0; i < N; i++){
    if(v[i] == v[A-1]){
      p++;
      if(i < A){
        q++;
      }
    }
  }

  ll cnt = 0LL;
  if(q == A){
    for(q = A; q <= B; q++){
      cnt += com[p][q];
    }
  }else{
    cnt += com[p][q];
  }

  cout.precision(20);

  cout << fixed << max_avr << endl;

  cout << cnt << endl;

  return 0;
}
