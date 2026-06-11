#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    int n; cin >> n;
    map<int, int> m;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        m[a]++;
    }

    int ans = m.size();
    if(ans % 2 == 0) cout << ans - 1 << endl;
    else cout << ans << endl;
}
