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
    string s;
    cin >> s;

    string target = ",";     // 検索文字列
    string replacement = " "; // 置換文字列

    // cout << s << endl;
    
    if (!target.empty()) {
        string::size_type pos = 0;
        while ((pos = s.find(target, pos)) != std::string::npos) {
            s.replace(pos, target.length(), replacement);
            pos += replacement.length();
        }
    }
    cout << s << endl;
    return 0;
}