#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50, LOGN = 18;

int n, cor[N];
int l;
int jp[LOGN][N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> cor[i];
    cin >> l;
    for(int i = 0; i < n - 1; i++) {
        jp[0][i] = (int)(upper_bound(cor, cor + n, cor[i] + l) - cor - 1);
    }
    jp[0][n-1] = n;
    for(int i = 1; i < LOGN; i++) {
        for(int j = 0; j < n; j++) {
            int nxt = jp[i-1][j];
            jp[i][j] = nxt == n ? n : jp[i-1][nxt];
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int a, b; cin >> a >> b; a--, b--;
        if(a > b) swap(a, b);
        int cur = a, res = 0;
        for(int i = LOGN - 1; i >= 0; i--) {
            if(jp[i][cur] < b) {
                cur = jp[i][cur];
                res += (1 << i);
            }
        }
        cout << res + 1 << "\n";
    }
}