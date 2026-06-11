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
    cin >> N;

    vector<ll> A(N);
    vector<ll> B(N);

    ll start = 0;
    bool first = true;
    REP(i, N){
        cin >> A[i];
        if(first){
            if(A[i] != 0){
                // cout << i << " " << A[i] << endl;
                start = i;
                first = false;
            }
        }
        if(i==0){
            B[i] = A[i];
        }
        else{
            B[i] = A[i] + B[i-1];
        }
    }

    // REP(i, N){
    //     cout << B[i] << endl;
    // }
    ll ans1 = 0;
    ll total1 = 0;

    total1 = -1;

    if(start == 0){
        total1 = 0;
    }

    for(ll i=start; i<N; i++){
        if((i-start)%2==0){
            if(B[i] + total1 <= 0){
                ans1 += abs(B[i]+total1) + 1;
                total1 += abs(B[i]+total1) + 1;
            }
        }
        else{
            if(B[i] + total1 >= 0){
                ans1 += abs(B[i]+total1) + 1;
                total1 -= (abs(B[i]+total1) + 1);
            }
        }
        // cout << "total:" << total << endl;
        // cout << "ans:" << ans << endl;  
    }

    ll total2 = 1;
    ll ans2 = 0;

    if(start == 0){
        total2 = 0;
    }

    for(ll i=start; i<N; i++){
        if((i-start)%2==0){
            if(B[i] + total2 >= 0){
                ans2 += abs(B[i]+total2) + 1;
                total2 -= (abs(B[i]+total2) + 1);
            }
        }
        else{
            if(B[i] + total2 <= 0){
                ans2 += abs(B[i]+total2) + 1;
                total2 += (abs(B[i]+total2) + 1);
            }
        }
    }

    
    // cout << ans << endl;
    // cout << start << endl;
    ll ans = min(ans1, ans2);

    if(start != 0){
        ans += 2*start-1;
    }
    cout << ans << endl;
    return 0;
}