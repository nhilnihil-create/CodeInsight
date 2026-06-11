  #include <bits/stdc++.h>
  using namespace std;

  const int MOD = 1000000007;

  //long long
  using ll = long long;

  //出力系
  #define print(x) cout << x << endl
  #define yes cout << "Yes" << endl
  #define YES cout << "YES" << endl
  #define no cout << "No" << endl
  #define NO cout << "NO" << endl
  
  // begin() end()
  #define all(x) (x).begin(),(x).end()

  //for
  #define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

  //最大公約数（ll）
  ll gcd(ll x, ll y) { return y ? gcd(y,x%y) : x;}

  //素因数分解
  vector<pair<ll, int>>factorize(ll n){
    vector<pair<ll, int>> res;
    for(ll i = 2; i * i <= n; ++i){
      if(n % i) continue;
      res.emplace_back(i, 0);
      while(n % i == 0){
        n /= i;
        res.back().second++;
      }
    }
  if(n != 1) res.emplace_back(n, 1);
  return res;
  }


int ans = MOD;

void dfs(int f, int e){

}

int main() {
int N;
cin >> N;
int mi = MOD, ma = 0, score = MOD;
REP(i, N){
    int a, b;
    cin >> a >> b;
    mi = min(mi, a);
    ma = max(ma, a);
    score = min(score, b);
}

int ans = mi + (ma - mi) + score;
print(ans);


}

