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
    ll N, L;
    cin >> N >> L;

    vector<ll> A(N);
    vector<ll> B(N-1);

    REP(i, N){
        cin >> A[i];
    }
    REP(i, N-1){
        B[i] = A[i] + A[i+1];
    }

    ll bmax = 0;
    ll bid = 0;
    REP(i ,N-1){
        if(B[i] > bmax){
            bmax = B[i];
            bid = i;
        }
    }
    if(bmax < L){
        cout << "Impossible" << endl; 
    }
    else{
        cout << "Possible" << endl; 
        for(ll i=0; i<=bid-1; i++){
            cout << i+1 << endl;
        }
        for(ll i=N-2; i>=bid+1; i--){
            cout << i+1 << endl;
        }
        cout << bid+1 << endl;
    }
    return 0;
}