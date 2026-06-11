#include <iostream>     // Cでいうstdio.h 標準入出力ライブラリ
#include <algorithm>    // ソート
#include <vector>       // 可変長配列
using namespace std;    // 名前空間
int main(void){

    // int変数定義
    int num1, num2;
    // コンソール入力
    cin >> num1, cin >> num2;

    // 配列定義
    vector<string> strvec(num1);

    //cout << "before:";
    // num1(N)の文だけループし、文字列(L)を標準入力で配列に格納
    for(int i = 0; i < num1; i++) {
        cin >> strvec[i];
        //cout << strvec[i];
    }
    
    // ソート
    sort(strvec.begin(), strvec.end());
    
    // ソート結果表示
    //cout << "\n" << "after:";
    for(int i = 0; i < num1; i++) {
        cout << strvec[i];
    }
}