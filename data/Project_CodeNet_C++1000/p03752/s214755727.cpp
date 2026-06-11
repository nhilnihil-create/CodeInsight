#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm(c++17)
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//イテレータあるけど順序保持しないmap
#include<unordered_set>//イテレータあるけど順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列
using namespace std;

typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000 //10^12
#define MOD 10000007 //10^9+7
#define MAXR 100000 //10^5:最大のrange(素数列挙などで使用)

int main(void){
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];

    unsigned int max_n = pow(2, n-1);
    ll min_cost = INF;
    for(unsigned int i=0; i<max_n; i++) {
        bitset<24> bs(i);
        if(bs.count() != k-1) continue;
        ll last = a[0];
        ll cost = 0;
        for(int j=0; j<n-1; j++) {
            if(!bs[j]) {
                last = max(last, a[j+1]);
                continue;
            }
            if(last >= a[j+1]) {
                last = last+1;
                cost += last - a[j+1];
            } else {
                last = a[j+1];
            }
        }
        min_cost = min(min_cost, cost);
    }

    cout << setprecision(12) << min_cost << endl;
    return 0;
}