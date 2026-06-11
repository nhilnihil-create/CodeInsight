#include <iostream>
#include <string>
#include <vector>
typedef unsigned int UINT;
using namespace std;
//が YAKI から始まるなら Yes を、そうでないなら No を出力せよ。



int main(void) {
    string S;
    cin >> S;
    string chack = S.substr(0, 4);
    if (chack.compare("YAKI") == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}