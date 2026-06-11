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
    int N, C, K;
    cin >> N >> C >> K;
    vector<int> T(N);
    REP(i,N) cin >> T[i];

    sort(ALL(T));
    int c = 0, time = 0;;
    int ans = 0;
    c = 1, time = T[0];
    FOR(i,1,N) {
        if (T[i] - time > K || c >= C) {
            ans++;
            c = 0;
        }
        if (c == 0) {
            time = T[i];
            c++;
        } else {
            c++;
        }
    }
    ans++;

    cout << ans << '\n';

    return 0;
}