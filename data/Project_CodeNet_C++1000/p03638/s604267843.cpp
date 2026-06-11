#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 998244353;

const int maxn = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    int ans[n][m];
    int x = 0, y = 0;
    for (int i = 1 ; i <= k ; i++) {
        int t;
        cin >> t;
        while(t--) {
            ans[x][y] = i;
            if (x%2==0) {
                if (y == m - 1) {
                    x++;
                }
                else {
                    y++;
                }
            }
            else {
                if (y == 0) {
                    x++;
                }
                else {
                    y--;
                }
            }
        }
    }
    f(n) {
        fr (j, 0, m) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}