#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;
int r , c , n , a[N];
int ans[105][105];
int main() {
    abdelrahman010
    cin >> r >> c >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    int lstr = 0 , lstc = 0 , d = 1;
    for(int i = 1;i <= n;i++) {
        while(a[i]--) {
            ans[lstr][lstc] = i;
            lstc += d;
            if(lstc == c)
                d = -1 , lstc-- , lstr++;
            else if(lstc == -1)
                d = 1 , lstc++ , lstr++;
        }
    }
    for(int i = 0;i < r;i++ , cout << '\n')
        for(int j = 0;j < c;j++)
            cout << ans[i][j] << " ";
    return 0;
}
