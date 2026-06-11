#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    string S; cin >> S;
    map<char, set<int>> M;
    rep(i,S.size()) {
        M[S[i]].insert(i);
    }

    for (auto x : M) {
        char c = x.first;
        auto j = begin(M[c]);
        int prev = *j;
        for (++j; j != end(M[c]); j++) {
            if (*j - prev <= 2) {
                cout << prev + 1 << " " << *j + 1 << endl;
                return 0;
            }
            prev = *j;
        }
    }
    cout << "-1 -1" << endl;
}
