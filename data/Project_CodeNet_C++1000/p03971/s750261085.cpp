#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    string S;
    cin >> S;

    int na = 0, nb = 0;
    rep(i, N) {
        bool ok = false;
        if (S[i] == 'a' && na + nb < A + B) {
            ok = true;
            na++;
        } else if (S[i] == 'b' && na + nb < A + B && nb < B) {
            ok = true;
            nb++;
        }
        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}