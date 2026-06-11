#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<climits>//long long型の最大値(LLONG_MAX)など
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<iterator>//集合演算(積集合,和集合,差集合など)
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
typedef long double ld;

#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    vector<pair<ld,ld>> set(4);
    set[0].second = 0.25;
    set[1].second = 0.5;
    set[2].second = 1;
    set[3].second = 2;

    cin >> set[0].first >> set[1].first >> set[2].first >> set[3].first;
    ld N;
    cin >> N;

    set[0].first *= 8;
    set[1].first *= 4;
    set[2].first *= 2;
    set[3].first *= 1;

    sort(set.begin(),set.end());

    rep(i,4){
        if(set[i].second == 0.25){
            set[i].first /= 8;
        }else if(set[i].second == 0.5){
            set[i].first /= 4;
        }else if(set[i].second == 1){
            set[i].first /= 2;
        }else if(set[i].second == 2){
            set[i].first /= 1;
        }
    }

    ll result = 0;
    while(N>0){
        rep(i,4){
            if(N >= set[i].second){
                ll tmp = N / set[i].second;
                N -= (set[i].second*tmp);
                result += (set[i].first*tmp);
                break;
            }
        }
    }

    cout << result << endl;

}
