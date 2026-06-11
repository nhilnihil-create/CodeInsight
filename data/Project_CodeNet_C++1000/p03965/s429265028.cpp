#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << endl;
#define CFYN(n) cout << ( (n) ? "YES":"NO") << endl;
using ll = long long;
using ull = unsigned long long;

int main(void)
{
    IOS
    string s;
    cin >> s;

    int ans = 0;

    REP(i,s.size()) {
        if (i < s.size() / 2) {
            ans += s[i] == 'p' ? 0: 1;
        } else {
            ans += s[i] == 'p' ? -1: 0;
        }
    }

    cout << ans << endl;

    return 0;
}