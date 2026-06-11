#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(j, m) for (int j = 0; j < (int)(m); j++)
#define rep2(i, l, n) for (int i = l; i < (int)(n); i++)


int main() {
    string S;
    cin >> S;
    vector<int> V(26,0);
    rep(i,S.size()) {
        V[S[i] - 'a']++;
    }
    int flag = 0;
    rep(j,26) {
        if (V[j] >= 2) {
            flag++;
        }
    }
    if (flag == 0) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
}

