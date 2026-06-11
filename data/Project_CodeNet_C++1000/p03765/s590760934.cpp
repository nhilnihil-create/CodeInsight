#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;
int n[2];
string s[2];
int asum[2][N], bsum[2][N];

int md(int x, int mod) {
    return (x % mod + mod) % mod;
}

int main() {
    cin >> s[0] >> s[1];
    for(int k = 0; k < 2; k++) {
        n[k] = s[k].length();
        s[k] = " " + s[k];
        for(int i = 1; i <= n[k]; i++) {
            asum[k][i] = asum[k][i-1] + (s[k][i] == 'A');
            bsum[k][i] = bsum[k][i-1] + (s[k][i] == 'B');
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int l[2], r[2];
        cin >> l[0] >> r[0] >> l[1] >> r[1];
        int sum[2];
        for(int k = 0; k < 2; k++) {
            sum[k] = md((bsum[k][r[k]] - bsum[k][l[k]-1]) - (asum[k][r[k]] - asum[k][l[k]-1]), 3);
        }
        cout << (sum[0] == sum[1] ? "YES" : "NO") << "\n";
    }
}