#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
typedef long long int ll;
using namespace std;

int main()
{
    int k, s;
    cin >> k >> s;

    ll ans = 0;
    rep(x, k + 1) {
        rep(y, k + 1) {
            int z = s - x - y;
            if (0 <= z && z <= k)
                ans++;
        }
    }
        
    cout << ans << endl;

    return 0;
}