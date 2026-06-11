#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    string s;
    cin >> s;

    int l = 0;
    rep(i, s.size()) {
        if(s[i] == 'A') {
            l = i;
            break;
        }
    }

    int r = 0;
    rep(i, s.size()) {
        if(s[s.size() - 1 - i] == 'Z') {
            r = s.size() - 1 - i;
            break;
        }
    }
    cout << r - l + 1 << endl;
}