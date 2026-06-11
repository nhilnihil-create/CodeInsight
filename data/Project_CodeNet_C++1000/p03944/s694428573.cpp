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

int main()
{
    cout << fixed << setprecision(15);
    ll W, H, N;
    cin >> W >> H >> N;

    vector<ll> X(N);
    vector<ll> Y(N);
    vector<ll> A(N);

    ll minx = 0;
    ll maxx = W;
    ll miny = 0;
    ll maxy = H;

    REP(i, N){
        cin >> X[i] >> Y[i] >> A[i];
        if(A[i] == 1){
            minx = max(minx, X[i]);
        }
        if(A[i] == 2){
            maxx = min(maxx, X[i]);
        }
        if(A[i] == 3){
            miny = max(miny, Y[i]);
        }
        if(A[i] == 4){
            maxy = min(maxy, Y[i]);
        }
    }
    cout << max(maxx-minx,0LL) * max(maxy-miny, 0LL) << endl;
    return 0;
}