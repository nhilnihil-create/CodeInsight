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
    return a*b/gcd(a, b);
}

int main()
{
    cout << fixed << setprecision(15);
    ll N;
    string S1, S2;
    cin >> N;
    cin >> S1;
    cin >> S2;

    vector<ll> P;
    REP(i, N){
        if(S1[i] == S2[i]){
            P.push_back(1);
        }
        else{
            P.push_back(2);
            i++;
        }
    }

    // for(auto p :P){
    //     cout << p << endl;
    // }

    ll K = P.size();

    ll ans = 1;
    REP(i, K){
        if(i == 0){
            if(P[i] == 1){
                ans = 3;
            }
            else{
                ans = 6;
            }
            continue;
        }

        if(P[i-1] == 1 && P[i] == 1){
            ans *= 2;
            ans = ans % MOD;
        }
        if(P[i-1] == 1 && P[i] == 2){
            ans *= 2;
            ans = ans % MOD;
        }
        if(P[i-1] == 2 && P[i] == 1){
            ans = ans % MOD;
        }
        if(P[i-1] == 2 && P[i] == 2){
            ans *= 3;
            ans = ans % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}