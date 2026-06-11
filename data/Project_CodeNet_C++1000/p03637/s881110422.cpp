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
    ll N;
    cin >> N;

    vector<ll> A(N);

    ll c2 = 0;
    ll c4 = 0;
    REP(i, N){
        cin >> A[i];
        if(A[i]%2 == 0) c2++;
        if(A[i]%4 == 0) c4++;
    }

    c2 = c2-c4;
    ll K = N-c2;

    if(c2 == N){
        cout << "Yes" << endl;
        return 0;
    }
    if(c2 == 0){
        if(K/2 <= c4){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
        return 0;
    }
    if((K-1)/2 < c4){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}