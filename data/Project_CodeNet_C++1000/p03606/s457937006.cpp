#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    int ans = 0;
    rep(i, n) {
        int l, r;
        cin >> l >> r;
        ans += ( r - l + 1);
    }
    cout << ans << endl;
    return 0;
}
