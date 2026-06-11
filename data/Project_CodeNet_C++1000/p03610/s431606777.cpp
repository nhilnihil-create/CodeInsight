#include<iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, x, n) for (int i = x; i < (n); ++i)
using namespace std;

int main() {
    string s;
    cin >> s;

    string res = "";

    // 文字列のサイズ分ループ
    rep(i, (int) s.size()) {
        if (i % 2 == 0) res += s[i];
    }

    cout << res << endl;
    return 0;
}
