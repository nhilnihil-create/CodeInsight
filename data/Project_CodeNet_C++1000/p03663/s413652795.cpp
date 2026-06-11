#include <cstdlib>
#include <iostream>
using namespace std;

#if 1
char query(string s) {
    cout << "? " << s << endl;
    char c;
    cin >> c;
    return c;
}

void answer(string s) {
    cout << "! " << s << endl;
}
#else
int ans = -1;
string ans_str;
char query(string s) {
    if (ans == -1) cin >> ans;
    // cerr << "query " << s << " " << atol(s.c_str()) << endl;
    ans_str = to_string(ans);
    bool b1 = atol(s.c_str()) <= ans,
        b2 = s <= ans_str;
    char ret = (b1 == b2 ? 'Y' : 'N');
    // cerr << "response " << ret << endl;
    return ret;
}

void answer(string s) {
    cerr << (s == ans_str ? "AC" : "WA")
         << " received answer " << s << ", expect " << ans_str << endl;
}
#endif

char binsearch(string &prefix, char min, char max, string &suffix) {
    char lb = min-1, ub = max;
    while (ub - lb > 1) {
        char c = (lb + ub) / 2;
        char ret = query(prefix + string(1, c) + suffix);
        if (ret == 'N') lb = c;
        else ub = c;
    }
    return ub;
}

int main() {
    string prefix(0, '0'), suffix(10, '9');
    for (int i = 0; i < 10; i++) {
        char c = binsearch(prefix, (i == 0 ? '1' : '0'), '9', suffix);
        prefix += c;
        suffix = suffix.substr(1);
    }
    prefix = prefix.substr(0, 10);
    int i = 9;
    for (;;) {
        if (prefix[i] != '0') { prefix[i]--; break; }
        else i--;
    }
    if (i > 0 || prefix[i] != '0') {
        while (query(prefix) == 'N') prefix.pop_back();
        prefix[i]++;
        answer(prefix);
    } else {
        // 100...0
        prefix[0] = '2';
        while (!prefix.empty() && query(prefix) == 'Y') prefix.pop_back();
        if (prefix.empty()) answer("1");
        else {
            prefix[0] = '1';
            answer(prefix + "0");
        }
    }
}
