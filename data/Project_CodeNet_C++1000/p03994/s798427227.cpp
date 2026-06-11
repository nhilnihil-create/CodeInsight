#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int K;
    cin >> K;
    REP(i, s.size()) {
        if (s[i] > 'a' && 'z' - s[i] + 1 <= K) {
            K -= 'z' - s[i] + 1;
            s[i] = 'a';
        }
    }
    s[s.size() - 1] = 'a' + (s.back() - 'a' + K) % 26;
    cout << s << endl;
}