#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N;
    string s;
    cin >> N >> s;
    vector<int> sheep(N), res(N);
    rep(i, N) {
        if (s[i] == 'o') res[i] = 1;
        else res[i] = 0;
    }
    rep(i, 2) rep(j, 2) {
        sheep[0] = i;
        sheep[1] = j;
        for (int k = 2; k < N; k++) {
            if (sheep[k - 1] ^ sheep[k - 2] ^ res[k - 1] == 1) sheep[k] = 1;
            else sheep[k] = 0;
        }
        if ((sheep[N - 1] ^ sheep[N - 2] ^ res[N - 1] ^ sheep[0] == 0) && (sheep[0] ^ sheep[N - 1] ^ res[0] ^ sheep[1] == 0)) {
            rep(k, N) {
                if (sheep[k] == 1) cout << "S";
                else cout << "W";
            }
            cout << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
}