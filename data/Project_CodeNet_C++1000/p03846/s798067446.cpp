#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>
#include <climits>

using namespace std;
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}
#define all(x) (x).begin(),(x).end()

using int64 = long long;
using P = pair<int64, int64>;

#define ng {ans=0;break;};

const int MOD = 1000000007;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());

    vector<P> l;
    l.emplace_back(a[0],0);
    for (int i=0; i<n; i++) {
        if (l.back().first == a[i]) l.back().second++;
        else l.emplace_back(a[i], 1);
    }

    int64 pre = -1;
    if (n%2 && l.back().first==0 && l.back().second == 1) {
        pre = 0;
        l.pop_back();
    }
    

    n = l.size();
    int64 ans = 1;
    for (int i=n-1; i>=0; i--) {
        if (pre+2 != l[i].first) ng;
        if (l[i].second != 2) ng;
        if (l[i].first == 0) ng;
        pre = l[i].first;
        ans *= 2;
        ans %= MOD;
    }
    cout << ans << endl;
}
