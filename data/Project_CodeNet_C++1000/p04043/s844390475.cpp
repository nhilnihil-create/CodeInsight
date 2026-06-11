#include <iostream>     // Cでいうstdio.h 標準入出力ライブラリ
using namespace std;    // 名前空間

int main(void){

    // int変数定義
    int num1, num2, num3;

    // コンソール入力
    cin >> num1, cin >> num2, cin >> num3;

    if(num1 + num2 + num3 == 17) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
