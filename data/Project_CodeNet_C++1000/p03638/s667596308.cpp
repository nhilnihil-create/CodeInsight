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
    ll H, W;
    cin >> H >> W;

    ll N;
    cin >> N;

    vector<ll> A(N);

    REP(i, N){
        cin >> A[i];
    }

    vector<vector<ll>> ans(H, vector<ll>(W, -1));

    ll total = 0;

    REP(i, N){
        REP(j, A[i]){
            ll h = total/W;
            ll w = total%W;
            // cout << total << " " << h << " " << w << endl;
            if(h%2 == 1){
                w = W-w-1;
            }
            // cout << total << " " << h << " " << w << endl;
            ans[h][w] = i+1;
            total++;
        }
    }

    REP(i, H){
        REP(j, W){
            if(j == W-1){
                cout << ans[i][j] << endl;
            }
            else{
                cout << ans[i][j] << " ";
            }
        }
    }
    return 0;
}