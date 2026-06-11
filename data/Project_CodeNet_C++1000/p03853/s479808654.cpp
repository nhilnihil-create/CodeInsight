
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> buffer;
    //reserveはstringが最適にメモリを確保できるよう、あらかじめサイズ変更の予定を指示する
    //計算量を削減できる
    buffer.reserve(h);
    rep(i,h){
        string tmp;
        cin >> tmp;
        // emplace_backは要素を追加する
        buffer.emplace_back(move(tmp));
    }
    for (int i = 0; i < 2 * h; i++){
        cout << buffer.at(i / 2) << endl;
    }

    
}