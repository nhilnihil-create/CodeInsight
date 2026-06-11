#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
template <class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    string s;
    cin >> s;

    vector<string> words = {"dreamer", "dream", "eraser", "erase"};

    while (s != "") {
        bool isChanged = false;
        for (const auto& word : words) {
            if (s.length() < word.length()) continue;
            if (s.find(word, s.length() - word.length()) != string::npos) {
                s         = s.substr(0, s.length() - word.length());
                isChanged = true;
#ifdef SOURCE_TEST

                cout << word << " " << s << endl;
#endif
                break;
            }
        }
        if (!isChanged) break;
    }

    cout << (s == "" ? "YES" : "NO") << endl;

    return 0;
}