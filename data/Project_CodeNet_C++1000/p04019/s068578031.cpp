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
    string S;
    cin >> S;

    vector<pair<char,int>> hougaku(4);
    hougaku[0] = make_pair('N',0);
    hougaku[1] = make_pair('S',0);
    hougaku[2] = make_pair('E',0);
    hougaku[3] = make_pair('W',0);

    ll sizeS = S.size();
    rep(i,sizeS){
        if(S[i] == hougaku[0].first){
            hougaku[0].second = 1;
        }else if(S[i] == hougaku[1].first){
            hougaku[1].second = 1;
        }else if(S[i] == hougaku[2].first){
            hougaku[2].second = 1;
        }else if(S[i] == hougaku[3].first){
            hougaku[3].second = 1;
        }
    }

    if(hougaku[0].second == 1 && hougaku[1].second == 1){
        if(hougaku[2].second == 1 && hougaku[3].second == 1){
            cout << "Yes" << endl;
            return 0;
        }else if(hougaku[2].second == 0 && hougaku[3].second == 0){
            cout << "Yes" << endl;
            return 0;
        }
    }else if(hougaku[0].second == 0 && hougaku[1].second == 0){
        if(hougaku[2].second == 1 && hougaku[3].second == 1){
            cout << "Yes" << endl;
            return 0;
        }else if(hougaku[2].second == 0 && hougaku[3].second == 0){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}

