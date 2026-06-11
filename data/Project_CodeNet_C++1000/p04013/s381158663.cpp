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

ll dp[52][52][2500];

int main()
{
    cout << fixed << setprecision(15);
    ll N, A;
    cin >> N >> A;

    vector<ll> X(N);

    REP(i, N){
        cin >> X[i];
    }

    Fill(dp, 0);

    dp[0][0][0] = 1;

    for(ll i=0; i<=N; i++){
        for(ll j=0; j<=N; j++){
            for(ll k=0; k<=2500; k++){
                if(i==0 && j==0 && k == 0){
                    dp[i][j][k] = 1;
                }
                else if(i>=1 && k<X[i-1]){
                    dp[i][j][k] = dp[i-1][j][k];
                }
                else if(i>=1 && j>=1 && k>=X[i-1]){
                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-X[i-1]];
                }
                else{
                    dp[i][j][k] = 0;
                }
            }
        }
    }

    ll ans = 0;
    for(ll k=1; k<=N; k++){
        ans += dp[N][k][k*A];
    }

    cout << ans << endl;
    return 0;
}