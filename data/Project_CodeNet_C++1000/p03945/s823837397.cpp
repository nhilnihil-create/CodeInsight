#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int main() {
    string S;
    cin >> S;
    vector<char> s;
    rep(i, S.size()) {
        if (S[i] == S[i + 1]) continue;
        s.push_back(S[i]);
        // cout << s[i] << ' ';
    }
    cout << s.size() - 1 << endl;
}
