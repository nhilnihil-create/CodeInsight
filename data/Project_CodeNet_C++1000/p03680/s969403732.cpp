#include <bits/stdc++.h>
using namespace std;

int main() {
    /* 入力処理 */
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i =0;i<N;i++) {
        cin >> a.at(i);
    }

    /* 変数宣言 */
    int count = 0; //ボタンを押した回数のカウンター
    int j = 0; //最初のボタン1(すなわち、j=0)

    /* ボタンを押していく */
    for(int i=0;i<N;i++) {
        count++; // ボタンを押した回数のカウンター

        if(a.at(j) == 2) { //もしボタンjを押してボタン2に行ったら
            cout << count << endl; //ボタンを押した回数を出力して、プログラムの終了
            exit(0); //プログラムの強制終了
        }

        j = a.at(j) - 1; //次のボタンの番号（配列は0スタートのため、-1する）
    }
    
    cout << -1 << endl; //for文でN個のボタンに対して計算しても、ボタン2に至らなかった場合、-1を出力
}