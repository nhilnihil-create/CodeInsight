#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define repp(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define all(v) v.begin(), v.end()
#define dump(v)                  \
    cerr << #v ":[ ";            \
    for (auto macro_vi : v) {    \
        cerr << macro_vi << " "; \
    }                            \
    cerr << "]" << endl;
#define ddump(v)                           \
    cerr << #v ":" << endl;                \
    for (auto macro_row : v) {             \
        cerr << "[";                       \
        for (auto macro__vi : macro_row) { \
            cerr << macro__vi << " ";      \
        }                                  \
        cerr << "]" << endl;               \
    }
using lint       = long long;
const int INF    = 1e9;
const lint LINF  = 1e18;
const lint MOD   = 26;
const double EPS = 1e-10;

int main() {
    string S;
    int K;
    cin >> S >> K;
    vector<int> T(S.size());
    for (int i = 0; i < S.size(); i++) {
        T[i] = S[i] - 'a';
    }
    for (int i = 0; i < S.size(); i++) {
        if (i == S.size() - 1) {
            T[i] = (T[i] + K % 26) % 26;
            continue;
        }
        if(T[i]==0){
            continue;
        }
        int need = 26 - T[i];
        if (need <= K) {
            T[i] = 0;
            K -= need;
        } else {
            continue;
        }
    }
    dump(T);
    string ans;
    for (int i = 0; i < T.size(); i++) {
        char c = 'a' + T[i];
        ans.push_back(c);
    }

    cout << ans << endl;
    return 0;
}