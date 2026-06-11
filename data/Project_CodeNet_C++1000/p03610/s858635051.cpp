#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(j, m) for (int j = 0; j < (int)(m); j++)
#define rep2(i, l, n) for (int i = l; i < (int)(n); i++)


int main() {
    string S;
    cin >> S;
    rep(i,S.size()) {
        if (i%2 == 0) {
            cout << S[i];
        }
    }
    cout << endl;
}

