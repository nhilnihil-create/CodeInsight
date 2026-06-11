#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
#define Reve(a) reverse(a.begin(), a.end())
#define PI 3.14159265359
typedef long long ll;
const ll MOD = 1e9+7;

ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b, a%b);
}
/*ll myPow(ll x, ll n, ll m){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return myPow(x * x % m, n / 2, m);
  else
    return x * myPow(x, n - 1, m) % m;
}*/

ll lcm(ll a, ll b){
  ll g = gcd(a, b);
  b /= g;
  a *= b;
  return a;
}

//素数判定 O(√n)
bool is_prime(int64_t n){
  for(int64_t i = 2; i*i<=n; i++){
    if(n%i==0) return false;
  }
  return n!=1;
}

//約数の列挙 O(√n)
vector<int64_t> dividor(int64_t n){
  vector<int64_t> res;
  for(int64_t i=1; i*i<=n; i++){
    if(n%i==0){
      res.push_back(i);
      if(i != n/i) res.push_back(i);
    }
  }
  return res;
}

//素因数分解 O(√n)
map<int64_t, int64_t> prime_factor(int64_t n){
  map<int64_t, int64_t> res;
  for(int64_t i=2; i*i<=n; i++){
    while(n%i==0){
      res[i]++;
      n /= i;
    }
  }
  if(n != 1) res[n] = 1;
  return res;
}
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};



int main(){
  int n, m, k, i, j; cin >> n >> m >> k;
  int d=0; int ch=0;
  for(i=0; i<=n; i++){
    for(j=0; j<=m; j++){
    d = i*m;
      d += (n-i)*j;
      d -= i*j;
      if(d==k){
      cout << "Yes" << endl;
      ch=1;
      break;
    }
    }
    if(ch==1) break;
  }
  if(ch==0){
  for(i=0; i<=m; i++){
    //d = i*n;
    //cout << d << endl;
    for(j=0; j<=n; j++){
      d = i*n;
      d += (m-i)*j;
      d -= i*j;
      if(d==k){
      cout << "Yes" << endl;
      ch=1;
      break;
    }
    }
    //cout << d << endl;
    if(ch==1) break;

  }
  }
  if(ch==0) cout << "No" << endl;
}