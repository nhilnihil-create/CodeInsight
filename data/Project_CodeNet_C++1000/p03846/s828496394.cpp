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

// コンビネーションを計算する関数
ll modpow(ll a, ll n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main()
{
    cout << fixed << setprecision(15);
    ll N;
    cin >> N;

    map<ll, ll> M;

    REP(i, N){
        ll a;
        cin >> a;
        M[a]++;
    }

    if(N%2 == 0){
        ll k = N/2;
        for(ll i=1; i<=N-1; i=i+2){
            if(M[i] != 2){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    else{
        ll k = N/2;
        if(M[0] != 1){
            cout << 0 << endl;
            return 0;
        }
        for(ll i=2; i<=N-1; i=i+2){
            if(M[i] != 2){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    ll k=N/2;
    cout << modpow(2, k) << endl;
    return 0;
}