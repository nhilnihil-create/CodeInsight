#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
//xにはvectorなどのコンテナ
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define sz(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    int n;cin>>n;
    int b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0;
    int ex=0;
    rep(q,n){
        int a;cin>>a;
        if(1<=a&&a<=399){
            b=1;
        }
        else if(a<=799){
            c=1;
        }
        else if(a<=1199){
            d=1;
        }
        else if(a<=1599){
            e=1;
        }
        else if(a<=1999){
            f=1;
        }
        else if(a<=2399){
            g=1;
        }
        else if(a<=2799){
            h=1;
        }
        else if(a<=3199){
            i=1;
        }else{
            ex++;
        }
    }
    int ans=b+c+d+e+f+g+h+i;
    if(ans==0){
        cout<<1<<endl;
    }
    else{cout<<ans<<" ";}
    
        cout<<ans+ex<<endl;
   
    return 0;
}