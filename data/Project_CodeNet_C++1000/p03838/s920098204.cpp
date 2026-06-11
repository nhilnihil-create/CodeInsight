#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS
    int X, Y;
    cin >> X >> Y;
    int ans = 1 << 30;
    vector<int> dx{1,1,-1,-1};
    vector<int> dy{1,-1,1,-1};
    REP(i,4) {
        int nx = X * dx[i];
        int ny = Y * dy[i];
        int b = dx[i] == -1 ? 1:0;
        b += dy[i] == -1 ? 1:0;
        if (nx <= ny) ans = min(ans,abs(nx-ny)+b);
    }

    cout << ans << '\n';

    return 0;
}