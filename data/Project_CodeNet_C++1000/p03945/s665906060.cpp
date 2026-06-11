#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string S;
    cin >> S;
    char left = S.at(0);
    int ans = 0;
    rep(i,S.size()) {
        if (S.at(i) != left) {
            ++ans;
            left = S.at(i);
        }
    }
    cout << ans << endl;
}

