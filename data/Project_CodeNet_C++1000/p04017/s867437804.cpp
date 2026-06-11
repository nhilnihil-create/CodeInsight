#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
int s[N], nxt[N][30];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, L, q;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    cin >> L >> q;
    for(int i = 1; i <= n; i++) {
        int l = i + 1, r = n, res = n+1;
        while(l <= r) {
            int mid = l + r >> 1;
            if(s[mid] <= s[i] + L) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        nxt[i][0] = res;
        // cout << i << "->" << res << '\n';
    }
    for(int i = 1; i < 30; i++) {
        for(int j = 1; j <= n; j++) {
            nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
            if(nxt[j][i - 1] >= n) {
                nxt[j][i] = n + 1;
            }
            // printf("nxt[%d][%d]:%d\n", j, i, nxt[j][i]);
        }
    }
    while(q--) {
        int a, b;
        cin >> a >> b;
        int l = 1, r = n, res = 0;
        if(a > b) swap(a, b);
        while(l <= r) {
            int mid = l + r >> 1;
            int val = mid, aa = a;
            // val = 2;
            for(int i = 0; i < 30; i++) {
                if((val >> i) & 1) {
                    aa = nxt[aa][i];
                    if(aa >= n) aa = n;
                }
            }
            // cout << ">" << a << endl;
            if(aa >= b) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << res << '\n';
    }
    return 0;
}