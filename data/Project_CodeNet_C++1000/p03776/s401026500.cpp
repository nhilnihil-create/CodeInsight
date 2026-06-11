#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
const ll MOD = 583964556541679;
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

// combinationの計算
long long com[51][51];

void cominit(){
    for (int i = 1; i < 51; ++i) {
        for (int j = 0; j <= i; ++j) {
            com[i][j] += com[i-1][j];
            if (j > 0) com[i][j] += com[i-1][j-1];        
        }
    }
}
    

int main()
{
    cout << fixed << setprecision(20);
    ll N, A, B;
    cin >> N >> A >> B;

    vector<ll> V(N);

    REP(i, N){
        cin >> V[i];
    }
    
    sort(V.rbegin(), V.rend());

    // 前処理
    com[0][0] = 1;
    cominit();

    ll t = V[A-1];
    bool flag = true;
    ll check = 0;
    ll count = 0;
    REP(i, N){
        if(V[i] == t){
            if(flag){
                check = i;
                flag = false;
            }
            count++;
        }
    }

    ll ans = 0;
    if(V[0] == V[check]){
        for(ll i=A; i<=B; i++){
            ans += com[count][i] ;
            // cout << "nCr:" << com[count][i] << endl;
            // cout << ans << endl;
        }
        // cout << count << endl;
        cout << V[0] << endl;
        cout << ans << endl;
        return 0;
    }

    ans += com[count][A-check];
    
    ll total = 0;
    REP(i, A){
        total += V[i];
    }
    
    cout << double(total)/double(A) << endl;
    cout << ans << endl;
    return 0;
}