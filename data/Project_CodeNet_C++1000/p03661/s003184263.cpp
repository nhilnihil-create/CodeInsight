#include <iostream>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<list>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n;i++)
#define ALL(a)  (a).begin(),(a).end()
const int MOD = 1000000007;
ll n, m, c, k,sum = (1LL << 60);
int main() {
    cin >> n; vector<ll> a(n,0);
    rep(i, n) {
        cin >> m;
        if (i == 0) a[i] = m;
        else a[i] = a[i - 1] + m;
    }
    rep(i, n - 1) {
        c = a[i]; k = a[n - 1] - c;
        sum = min(abs(k - c), sum);
    }
    cout << sum << endl;
}