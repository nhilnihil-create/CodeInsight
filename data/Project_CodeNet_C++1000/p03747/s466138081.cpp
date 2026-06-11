#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define PRINT(v) for (auto x : (v)) cout <<x <<" " ; cout <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using mat = vector<vector<ll>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
const int inf = 1001001001;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }

template<class T> struct edge { int to; T cost;};

ll N,L,T;

ll collision(ll x1,ll w1,ll x2,ll w2){
  // 蟻1と2が何回衝突するか
  // 向きが同じなら衝突しない
  if (w1 == w2) return 0;
  // 簡単のため、1が時計回り、2が反時計回りに移動するとする
  if (w1 == -1){ swap(x1, x2); swap(w1, w2);}
  // 2が原点に来るように各々の座標を調整。1が負なら正にしとく
  x1 -= x2; x2 -= x2;
  if (x1 < 0) x1 += L;
  // 結局、x1が時計回りに2Tだけ動いた時に何回原点を通るかという問題に帰着できる
  ll res = (x1 + 2*T) / L;
  return res;
}

int main() {
  cin >>N >>L >>T;
  vector<ll> x(N),w(N); rep(i, N) cin >>x[i] >>w[i];
  rep(i, N) if (w[i] == 2) w[i] = -1;
  
  // 座標自体は衝突を無視して計算すればいい
  // 各々がどの蟻かについては、x[0]の蟻についてT秒で衝突する蟻の個数を求める
  // それをそのまま足すか引くかすればその座標の蟻がどの蟻か決定する
  ll ant0 = 0;
  // x[0]にいた蟻について調査
  for (int i=1; i<N; i++){
    ant0 += w[0] * collision(x[0], w[0], x[i], w[i]);
  }
  ll colli = abs(ant0);
  if (ant0 >= 0) ant0 %= N;
  else{ ant0 *= -1; ant0 %= N; ant0 = (N-ant0) % N; }

  // 座標を再計算
  for (int i=0; i<N; i++){
    x[i] += T * w[i];
    if (x[i] >= 0) x[i] %= L;
    else{ x[i] *= -1; x[i] %= L; x[i] = (L - x[i]) % L; }
  }
  // ant0 : x[0]の蟻が実際にはどの蟻か
  int index = ant0;
  int indexco = x[0];
  // 現在、蟻index は indexco にいる
  sort(all(x));
  // 各々の蟻は座標順に存在すると考えられる
  // colli : 何回衝突したか。
  // ただし、同じ座標の蟻が存在しうる。
  // この場合、w[0] = 1なら若い方、w[0] = -1なら若くない方。
  vector<ll> res(N);
  res[index] = indexco;
  for (int j=0; j<N; j++){
    if (x[j] == indexco){
      if (x[(j+1)%N] == indexco) if (w[0] == 1) j = (j+1+N)%N;
      for (int i=0; i<N; i++){
        res[(i+index)%N] = x[(j+i)%N];
      }
      break;
    }
  }

  // たとえば1であれば、蟻0から蟻N-1の座標は各々x[N-1], x[0], x[1], ..., x[N-2] となる
  for (int i=0; i<N; i++){
    cout <<res[i] <<endl;
  }
}