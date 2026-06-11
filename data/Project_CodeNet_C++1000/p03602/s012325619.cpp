#include <bits/stdc++.h>

using namespace std;

const int NMAX = 305;

long long v[NMAX][NMAX];
bool muc[NMAX][NMAX];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            cin >> v[i][j];

    for(int i = 1; i <= n; i ++) {
        for(int j = i + 1; j <= n; j ++) {
            for(int k = 1; k <= n; k ++) {
                if(i != k && j != k && v[i][j] > (v[i][k] + v[k][j])) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = i + 1; j <= n; j ++) {
            for(int k = 1; k <= n; k ++) {
                if(i != k && j != k && v[i][j]) {
                    if(v[i][j] == v[i][k] + v[k][j]) {
                        muc[i][j] = 1;
                        muc[j][i] = 1;
                    }
                }
            }
        }
    }
    long long sol = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = i + 1; j <= n; j ++)
            if(muc[i][j] == 0)
                sol += v[i][j];
    cout << sol;
    return 0;
}
