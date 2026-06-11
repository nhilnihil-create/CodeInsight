#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main()
{
    int n;
    cin >> n;

    int m = 0, x = INF;
    rep(i, n){
        int a, b;
        cin >> a >> b;
        m = max(a, m);
        x = min(x, b);
    }

    int ans = m + x;
    cout << ans << "\n";

    return 0;
}
