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
    string S;
    cin >> S;

    ll N = S.length();

    map<char, ll> M;
    REP(i, N){
        M[S[i]]++;
    }

    ll count = 0;
    priority_queue<ll> que;
    for(auto iter=M.begin(); iter!=M.end(); iter++){
        que.push(iter->second);
        count++;
    }
    
    // 処理を一度も実行できない場合
    if(count == 2){
        cout << "Second" << endl;
        return 0;
    }

    que.pop();
    que.pop();

    ll third = que.top();

    // 処理が1回だけできる場合
    // if((count == 3) && (third == 1)){
    //     cout << "First" << endl;
    //     return 0;
    // }

    if(S[0] == S[N-1]){
        if((N-3)%2 == 0){
            cout << "Second" << endl;
        }
        else{
            cout << "First" << endl;
        }
    }
    else{
        if((N-2)%2 == 0){
            cout << "Second" << endl;
        }
        else{
            cout << "First" << endl;
        }
    }
    return 0;
}