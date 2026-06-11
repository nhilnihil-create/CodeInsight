#include <bits/stdc++.h>
using intl = long long;
using itnl = long long;//typo用
using itn = int;//typpo用
using ld = long double;
using namespace std;
#define rep(i, n) for(intl i = 0; i < (intl)(n); i++)
#define rrep(i, n) for(intl i = (intl)(n) - 1; i >= 0; i--)
#define repi(i, a, b) for(intl i = (intl)(a); i < (intl)(b); i++)
#define rrepi(i, a, b) for(intl i = (intl)(a); i > (intl)(b); i--)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,1,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define alength(a) (sizeof(a) / sizeof(a[0]))
#define debug(x) cout << #x << ":" << x << endl
#define rdebug(i,x) rep(i, alength(x))cout << #x << "[" << i << "]:" << x[i] << endl//1次元配列の出力
#define rrdebug(i, j, x) rep(i, alength(x))rep(j, alength(x[i]))cout << #x << "[" << i << "][" << j << "]:" << x[i][j] << endl//二次元配列の出力
#define pb push_back
#define mp make_pair
#define pii pair<intl,intl>
const intl INF = 1e9;
const intl MOD = 1e9+7;
const ld EPS = 1.0e-14;//-9
const ld PI = acos(-1);
void fp(bool f){cout << (f ? "Yes" : "No") << endl;}
void fp(bool f, string s, string t){cout << (f ? s : t) << endl;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) {a = b; return true;} return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) {a = b; return true;} return false; }
intl kai(intl k){//k!を求める関数
    intl a = 1;
    for(int i = 2; i <= k; i++){
        a *= i;
    }
    return a;
}
intl digit10(intl a){//aを10進数で表したときの桁数を求める関数
    intl b = 0;
    do{
        a /= 10;
        b++;
    }while(a);
    return b;
}

//--------------入力受け取る場所,分けてた方がデバッグしやすい気がする---------------------
string s;

void input_var(){
    cin >> s;
}
//-------------------------------------------------------------------------------


signed main(){
    cout << fixed << setprecision(10);
    input_var();
    reverse(all(s));
    string d,dr,e,er;
    d = "dream";reverse(all(d));
    dr = "dreamer";reverse(all(dr));
    e = "erase";reverse(all(e));
    er = "eraser";reverse(all(er));
    intl i = 0;
    intl len = s.length();
    bool f = true;
    while(i < len){
        if((s.substr(i,5) == d)||(s.substr(i,5) == e))i += 5;
        else if(s.substr(i,6) == er)i += 6;
        else if(s.substr(i,7) == dr)i += 7;
        else {
            f = false;
            break;
        }
    }
    fp(f,"YES","NO");
    return 0;
}