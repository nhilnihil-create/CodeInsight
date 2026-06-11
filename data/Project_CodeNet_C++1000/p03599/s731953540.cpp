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
    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    double d = 0.0;
    ll water = 0;
    ll sugar = 0;
    for(ll i=0; i<=30; i++){
        for(ll j=0; j<=30; j++){
            ll max_sugar = (i*A+j*B)*E;

            for(ll k=0; k<=max_sugar; k++){
                for(ll l=0; l<=max_sugar-k*C; l++){
                    if(k*C+l*D > (i*A+j*B)*E) break;
                    if(100*(i*A+j*B) + k*C+l*D > F) break;
                    double temp;
                    temp = 100 * double(k*C+l*D) / double(100*(i*A+j*B) + k*C+l*D);
                    if(temp >= d){
                        d = temp;
                        sugar = k*C+l*D;
                        water = 100*(i*A+j*B);
                    }
                }
            }
        }
    }
    cout << sugar + water << " " << sugar << endl;
    return 0;
}