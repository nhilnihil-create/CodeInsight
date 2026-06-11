#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;

int main(void) {
    string s;
    cin >> s;

    string result = "";
    for (Int i = 0; i < (Int)s.length(); ++i) {
        // 0か1が入力されたらその文字を追加し，Bが入力されたら文字列の一番右の文字を消す
        if (s[i] == '0' || s[i] == '1') {
            // 末尾に文字を挿入する
            result += s[i];
        } else if (s[i] == 'B' && result != "") {
            // 末尾の文字を削除する
            result.pop_back();
        }
    }
    cout << result << endl;
    return 0;
}

