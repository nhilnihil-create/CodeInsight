#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(j, m) for (int j = 0; j < (int)(m); j++)
#define rep2(i, l, n) for (int i = l; i < (int)(n); i++)


int main() {
    string S;
    cin >> S;
    rep2(i,'a','z' + 1) {
        int flag = 0;
        rep(j,S.size()) {
            if (S[j] == i) {
                flag++;
            }
        }
        if (flag == 0) {
            char c = i;
            cout << c << endl;
            break;
        }
        if (i == 'z') {
            cout << "None" << endl;
        }
    }

}

