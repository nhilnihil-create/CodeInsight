// failed to generate code
#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0 ; i < (int)(n) ; i++)
typedef long long ll;
typedef long double Double;

void main_(istream &cin) {
    int N;
    int g[300][300];
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> g[i][j];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (g[j][i] + g[i][k] < g[j][k]) {
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            bool important = true;
            for (int k = 0; k < N; k++) {
                if (i != k && j != k && g[i][k] + g[k][j] == g[i][j]) important = false;
            }
            if (important) ans += g[i][j];
        }
    }
    cout << ans << endl;
}


int main() {
#ifdef INTELLIJ
    ifstream ifs(string(INPUTS_DIR) + "in_1.txt");
    if (ifs.is_open()) {
        main_(ifs);
        ifs.close();
    } else {
        cerr << "Error: no input." << endl;
    }
#else
    ios::sync_with_stdio(false);
    cin.tie(0);
    main_(cin);
#endif
}


