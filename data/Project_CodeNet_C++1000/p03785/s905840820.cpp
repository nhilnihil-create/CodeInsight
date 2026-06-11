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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    rep(i, n) cin >> t[i];
    sort(t.begin(), t.end());
    ll cur = 0;
    ll ans = 0;
    while(cur<n){
        int nex = cur;
        while( nex < n && nex - cur < c && t[nex] - t[cur] <= k ) nex++;
        ans++;
        cur=nex;
    }
    cout << ans << endl;
    return 0;
}
