#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
string S[3];


void input() {
    rep(i, 3) cin >> S[i];
}


int main() {
    input();
    string ans = "";
    rep(i, 3) {
        char c = S[i][0];
        c -= 32;
        ans += c;
    }
    cout << ans << endl;
}
