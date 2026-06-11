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
    int N; cin >> N;
    int ans = 1;
    // 0-no 1-up 2-down
    int nud = 0;
    int cnt = 0;
    cin >> cnt;
    REP(i,N-1) {
        int a;
        cin >> a;

        if (nud == 0) {
            if (cnt < a) nud = 1;
            else if (cnt > a) nud = 2;
        }
        
        if (nud == 1) {
            if (cnt > a) {
                ans++;
                nud = 0;
            }
        }
        if (nud == 2) {
            if (cnt < a) {
                ans++;
                nud = 0;
            }
        }
        cnt = a;
    }

    cout << ans << '\n';

    return 0;
}