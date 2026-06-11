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

// pairsをfirstを優先キーとして昇順ソート
bool compare_by_a(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }
}

int main()
{
    cout << fixed << setprecision(15);
    ll N, K;
    cin >> N >> K;

    vector<P> p(N);

    REP(i, N){
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end(), compare_by_a);

    ll now = 0;
    REP(i, N){
        now += p[i].second;
        if(K <= now){
            cout << p[i].first << endl;
            return 0;
        }
    }
    return 0;
}