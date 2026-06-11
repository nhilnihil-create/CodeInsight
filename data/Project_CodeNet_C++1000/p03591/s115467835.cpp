// CF2017A.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <string>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    string head = s.substr(0, 4);
    if (s.size() < 4) {
        cout << "No" << endl;
        return 0;
    }
    if (head != "YAKI") {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
