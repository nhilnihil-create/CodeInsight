#include <bits/stdc++.h>
using namespace std;

#define vint vector<int>
#define vvint vector<vint>
#define sint stack<int>
#define qint queue<int>
#define rep(i, n) for(int i=0;i<(int)(n);i++) // 繰り返し処理
#define all(x) (x).begin(),(x).end() // 全体 こんな感じで使う→sort(all(a));
#define ct(a) cout << a << endl
#define iceil(a,b) (a+(b-1))/b //int ceil : 繰り上げの割り算 通常のceilではceil((7.0/2.0))のようにしなければならなかった。
#define ld long double
#define ll long long
#define ul unsigned long
vint CinLine(int N){vint v(N);for(int i=0;i<N;i++){cin >> v.at(i);}return v;}//cin line 連続でvectorに格納
void CoutLine(vint v){for(int i=0;i<v.size()-1;i++){cout<<v.at(i)<<" ";}cout << v.at(v.size()-1)<<endl;}

void Main(){
    string divide[4] = {"dream","dreamer","erase","eraser"};
    string S;
    cin >> S;

    // 左右反転
    reverse(all(S));
    rep(i,4){
        reverse(all(divide[i]));
    }
    // 端から切っていく
    bool isCan = true;
    for(int i = 0; i<S.size();){
        bool isDivide = false;
        for(int j = 0; j<4;j++){
            string d = divide[j];
            if(S.substr(i,d.size()) == d){
                isDivide = true;
                i += d.size();
            }
        }
        if(!isDivide){
            isCan = false;
            break;
        }
    }
    if(isCan) ct("YES");
    else ct("NO");

    return;
}

int main() {
    Main();
}
