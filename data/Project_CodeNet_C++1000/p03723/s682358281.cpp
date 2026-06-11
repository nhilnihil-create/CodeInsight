#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
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
    vector<int> v(3);
    REP(i,3) cin >> v[i];
    REP(i,3) {
        if (v[i] % 2 != 0) {
            OUT(0)
            return 0;
        }
    }

    if (v[0] == v[1] && v[1] == v[2]) {
        OUT(-1)
        return 0;
    }

    int ans = 0;
    bool loop = true;
    while(loop) {
        vector<int> tmp(3);
        REP(i,3) tmp[i] = v[(i+1) % 3] / 2 + v[(i+2) % 3] / 2;
        swap(tmp,v);
        ans++;
        REP(i,3) {
            if (v[i] % 2 != 0) loop = false;
        }
    }

    cout << ans << '\n';

    return 0;
}