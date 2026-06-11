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

ll dp[11][310][11];

int main()
{
    cout << fixed << setprecision(15);
    ll N, W;
    cin >> N >> W;

    vector<ll> w(N);
    vector<ll> v(N);

    REP(i, N){
        cin >> w[i] >> v[i];
    }

    ll k = w[0];
    ll a = 0;
    ll b = 0;
    ll c = 0;
    ll d = 0;

    vector<ll> A(N, 0);
    vector<ll> B(N, 0);
    vector<ll> C(N, 0);
    vector<ll> D(N, 0);

    REP(i, N){
        if(w[i] == k){
            A[a] = v[i];
            a++;
        }
        if(w[i] == k+1){
            B[b] = v[i];
            b++;
        }
        if(w[i] == k+2){
            C[c] = v[i];
            c++;
        }
        if(w[i] == k+3){
            D[d] = v[i];
            d++;
        }
    }
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());
    sort(D.rbegin(), D.rend());

    vector<ll> A2(a+1, 0);
    vector<ll> B2(b+1, 0);
    vector<ll> C2(c+1, 0);
    vector<ll> D2(d+1, 0);

    REP(i, a+1){
        if(i==0){
            A2[i] = 0;
            continue;
        }
        A2[i] = A2[i-1] + A[i-1];
    }
    REP(i, b+1){
        if(i==0){
            B2[i] = 0;
            continue;
        }
        B2[i] = B2[i-1] + B[i-1];
    }
    REP(i, c+1){
        if(i==0){
            C2[i] = 0;
            continue;
        }
        C2[i] = C2[i-1] + C[i-1];
    }
    REP(i, d+1){
        if(i==0){
            D2[i] = 0;
            continue;
        }
        D2[i] = D2[i-1] + D[i-1];
    }
    // cout << A2[1]+C2[1] << endl;
    ll ans = 0;
    REP(p, a+1){
        REP(q, b+1){
            REP(r, c+1){
                REP(s, d+1){
                    if(k*p + (k+1)*q + (k+2)*r + (k+3)*s > W) continue;
                    ans = max(ans, A2[p]+B2[q]+C2[r]+D2[s]);
                    // cout << "i:" << i << " j:" << j << " k:" << k << " l:" << l << " " << ans << endl;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}