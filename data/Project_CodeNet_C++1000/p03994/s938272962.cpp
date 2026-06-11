#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string s;
    int K;
    cin >> s >> K;
    
    rep(i, s.size() - 1) {
        if (s[i] == 'a') continue;
        if ('{' - s[i] <= K) {
            K -= ('{' - s[i]);
            s[i] = 'a';
        }
    }
    K %= 26;
    while (K > 0) {
        --K;
        ++s[s.size() - 1];
        if (s[s.size() - 1] == '{') s[s.size() - 1] = 'a';
    }
    cout << s << endl;
    return 0;
}

