#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    string s;
    int K;
    cin >> s >> K;
    rep(i, s.size()) {
        int d = ('a' + 26 - s[i]) % 26;
        if (K >= d) {
            s[i] = 'a';
            K -= d;
        }
    }
    s[s.size() - 1] = (s[s.size() - 1] - 'a' + K) % 26 + 'a';
    cout << s << "\n";
}