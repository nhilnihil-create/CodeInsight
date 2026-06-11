#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s; cin >> s;
    string t("YAKI");
    rep(i, min(s.size(),t.size())) {
        if (s.at(i) != t.at(i)) {
            puts("No");
            return 0;
        }
    }
    if (s.size() < t.size()) {
        puts("No");
    }
    else {
        puts("Yes");
    }

    return 0;
}