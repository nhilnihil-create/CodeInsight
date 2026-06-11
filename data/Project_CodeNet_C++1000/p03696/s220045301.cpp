#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
    int n;
    string s = "";
    string cor_ans = "";
    char c;
    int cnt=0, st = 0;
    cin >> n;
    for (int i =0; i < n; ++i) {
        cin >> c;
        if (c == '(') {
            ++st;
        } else if (c == ')') {
            --st;
        }
        if (st < 0) {
            ++cnt;
            st = 0;
        }
        s += c;
    }
    for (; st > 0; --st) {
        s += ')';
    }
    for (; cnt > 0; --cnt) {
        cor_ans += '(';
    }
    cor_ans += s;
    cout << cor_ans;
}

int main() {
	solve();
    return 0;
}
