#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>
#include <queue>
#include <stack>

using namespace std;

#define mod (1e9 + 7)
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()

typedef long long ll;

void solve1()
{
    int w, h, n; cin >> w >> h >> n;
    vector<int> x(n), y(n), a(n);
    rep(i, n) {
        cin >> x[i] >> y[i] >> a[i];
    }

    vector<vector<bool>> grid(h, vector<bool> (w));
    rep(i, h) {
        rep(j, w) {
            grid[i][j] = false;
        }
    }

    int ans = 0;

    rep(i, n) {
        if(a[i] == 1) {
            rep(j, h) {
                rep(k, x[i]) {
                    grid[j][k] = true;
                }
            }
        } else if(a[i] == 2) {
            rep(j, h)
            {
                for(int k = x[i]; k < w; k++) {
                    grid[j][k] = true;
                }
            }
        } else if(a[i] == 3) {

            rep(j, y[i])
            {
                rep(k, w)
                {
                    grid[j][k] = true;
                }
            }

            
        } else {
            for (int j = y[i]; j < h; j++)
            {
                rep(k, w)
                {
                    grid[j][k] = true;
                }
            }
        }
    }

    rep(i, h) {
        rep(j, w) {
            if(!grid[i][j]) {
                ans ++;
            }
        }
    }

    cout << ans << endl;

}

int main()
{
    solve1();
}