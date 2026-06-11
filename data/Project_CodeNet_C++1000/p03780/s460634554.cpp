#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int maxn = 6e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int pre[n + 5][k + 5] = {};
    int suf[n + 5][k + 5] = {};
    int v[n + 5] = {};
    pre[0][0] = 1;
    suf[n+1][0] = 1;
    for(int i = 1 ; i <= n ; i++) {
        cin >> v[i];
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j <= k ; j++) {
            if (pre[i - 1][j]) {
                pre[i][j] = 1;
            }
            if (j >= v[i] && pre[i - 1][j - v[i]]) {
                pre[i][j] = 1;
            } 
        }
    }
    for (int i = n ; i >= 1 ; i--) {
        for (int j = 0 ; j <= k ; j++) {
            if (suf[i + 1][j]) {
                suf[i][j] = 1;
            }
            if (j >= v[i] && suf[i + 1][j - v[i]]) {
                suf[i][j] = 1;
            } 
        }
    }
    for (int i = n + 1 ; i >= 1 ; i--) {
        for (int j = 1 ; j <= k ; j++) {
            suf[i][j] += suf[i][j-1];
        }
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        int lb = max(k - v[i], 0);
        int ub = k - 1;
        for (int j = 0 ; j < k ; j++) {
            if (pre[i - 1][j] == 0)continue;
            int rlb = max(lb - j,0);
            int rub = ub - j;
            int cnt = 0;
            if (rlb == 0) {
                cnt = suf[i+1][rub];
            }
            else {
                cnt = suf[i+1][rub] - suf[i+1][rlb-1];
            }
            if (cnt) {
                ans++;
                break;
            }
        }
    }
    cout << n - ans << '\n';

}