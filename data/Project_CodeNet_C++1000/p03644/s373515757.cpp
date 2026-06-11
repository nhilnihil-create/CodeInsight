#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    ll n;
    cin >> n;
    int ans = 0;
    int max_cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        int num = i;
        while(1) {
            if (num % 2 != 0) break;
            num /= 2;
            ++cnt; 
        }
        if (max_cnt <= cnt) {
            ans = i;
            max_cnt = cnt;
        }
    }
    cout << ans << endl;
    return 0;
}
