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
#define MOD 1000000007 //10^9+7
#define MAXR 100000 //10^5:最大のrange(素数列挙などで使用)


typedef map<string, int> map_type;
typedef pair<string, int> value_type;

struct second_order {
  bool operator()(const value_type& x, const value_type& y) const {
    if( x.second != y.second) return x.second < y.second;
    return x.first > y.first;
  }
};

typedef priority_queue<value_type, vector<value_type>, second_order> pqueue_type;


pqueue_type map_to_pqueue(map_type m) {
    pqueue_type que;
    for(auto it=m.begin(); it!=m.end(); ++it) {
        que.push(*it);
    }
    return que;
}


int main(void){
    ll q, h, s, d, n;
    cin >> q >> h >> s >> d;
    cin >> n;
    s = min(s, 2*min(h, 2*q));
    ll cost = 0;
    if(s*2 <= d) {
        cost = n*s;
    }else {
        cost = (n/2)*d + (n%2)*s;
    }
    cout << cost << endl;
    return 0;
}
