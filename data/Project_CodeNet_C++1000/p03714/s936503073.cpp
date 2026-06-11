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

    vector<ll> A(3*N);

    REP(i, 3*N){
        cin >> A[i];
    }

    ll f = 0;
    ll b = 0;

    priority_queue<ll, vector<ll>, greater<ll> > que1;
    vector<ll> F(N+1, 0);

    REP(i, N){
        f += A[i];
        que1.push(A[i]);
    }
    F[0] = f;
    for(ll i=N; i<2*N; i++){
        que1.push(A[i]);
        f += A[i];
        f -= que1.top();
        que1.pop();
        F[i-N+1] = f;
    }

    // cout << "test" << endl;
    priority_queue<ll> que2;
    vector<ll> B(N+1, 0);

    for(ll i=3*N-1; i>=2*N; i--){
        b += A[i];
        que2.push(A[i]);
    }
    B[0] = b;
    for(ll i=2*N-1; i>=N; i--){
        que2.push(A[i]);
        b += A[i];
        b -= que2.top();
        que2.pop();
        B[2*N-i] = b;
    }

    // cout << "F" << endl;
    // for(ll i=0; i<=N; i++){
    //     cout << F[i] << endl;
    // }
    // cout << "B" << endl;
    // for(ll i=0; i<=N; i++){
    //     cout << B[i] << endl;
    // }

    ll ans = -LINF;
    for(ll i=0; i<=N; i++){
        ans = max(ans, F[i] - B[N-i]);
    }
    cout << ans << endl;
    return 0;
}