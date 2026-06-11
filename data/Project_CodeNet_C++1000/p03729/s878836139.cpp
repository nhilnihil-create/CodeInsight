#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

char head_char(string s) {
    return s[0];
}

char tail_char(string s) {
    return s[s.size() - 1];
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    cout << (tail_char(a) == head_char(b) && tail_char(b) == head_char(c) ? "YES" : "NO") << endl;

    return 0;
}
