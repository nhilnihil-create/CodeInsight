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

ll dp[410][410];

int main()
{
    cout << fixed << setprecision(15);
    ll N;
    ll MA, MB;
    cin >> N >> MA >> MB;

    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N);

    REP(i, N){
        cin >> A[i] >> B[i] >> C[i];
    }

    Fill(dp, LINF);

    dp[0][0] = 0;

    REP(n, N){
        for(ll i=400; i>=0; i--){
            for(ll j=400; j>=0; j--){
                if(i < A[n]) continue;
                if(j < B[n]) continue;
                dp[i][j] = min(dp[i-A[n]][j-B[n]]+C[n], dp[i][j]);
            }
        }
    }
    
    // REP(i, 10){
    //         REP(j, 10){
    //             cout << "i:" << i << " j:" << j << " dp:" << dp[i][j] << endl;
    //         }
    // }
    ll ans = LINF;
    for(ll i=1; i<=400; i++){
        if(MA*i>400) break;
        if(MB*i>400) break;

        if(dp[MA*i][MB*i] != LINF){
            ans = min(ans, dp[MA*i][MB*i]);
            // cout << ans << endl;
        }
    }
    
    if(ans == LINF){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
    return 0;
}