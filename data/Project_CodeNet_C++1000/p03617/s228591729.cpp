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
    ll Q,H,S,D;
    cin >> Q >> H >> S >> D;
    ll N;
    cin >> N;
    Q *= 4;
    H *= 2;
    ll m = min(Q,min(H,S));
    ll ans = 0;
    if (m*2 <= D) ans = m * N;
    else ans = D * (N / 2) + m * (N%2);

    cout << ans << '\n';

    return 0;
}