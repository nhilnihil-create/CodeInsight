#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){

    // 文字数が偶数か奇数, 両端が同じか異なるかでどちらが勝つか決まる
    // パリティに注目
    // 最終的には
    // ababa
    // abab
    // の2パターン
    string s;
    cin >> s;
    if (s[0] == s.back()) {
        if (s.size() % 2) cout << "Second" << '\n';
        else cout << "First" << '\n';
    }
    else {
        if (s.size() % 2) cout << "First" << '\n';
        else cout << "Second" << '\n';
    }
}
