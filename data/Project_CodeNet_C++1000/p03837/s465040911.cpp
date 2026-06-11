#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// グラフ表現
using Graph = vector<vector<int>>;

// グラフの辺表現
using Edge = map<pair<int,int>,int>;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// 最大公約数
ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a/gcd(a, b) * b;
}

ll dist[110][110];

// ワーシャルフロイド
void warshall_floyd(int n) {
  for (int k = 0; k < n; k++){       // 経由する頂点
    for (int i = 0; i < n; i++) {    // 始点
      for (int j = 0; j < n; j++) {  // 終点
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}

int main()
{
    cout << fixed << setprecision(15);
    ll N, M;
    cin >> N >> M;

    Fill(dist, INF);

    vector<ll> A(M);
    vector<ll> B(M);
    vector<ll> C(M);

    REP(i, M){
        ll a, b, c;
        cin >> a >> b >> c;
        dist[a-1][b-1] = c;
        dist[b-1][a-1] = c;

        A[i] = a-1;
        B[i] = b-1;
        C[i] = c;
    }

    warshall_floyd(N);

    ll ans = 0;
    REP(i, M){
        if(dist[A[i]][B[i]] < C[i]) ans++;
    }

    cout << ans << endl;
    return 0;
}