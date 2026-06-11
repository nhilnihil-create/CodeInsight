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
    int N, M, K;
    cin >> N >> M >> K;
    if (N > M) swap(N,M);
    bool ans = false;
    REP(i,N+1) {
        int count = M*i;
        int md = N - i*2;
        int rest = K-count;
        if (md == 0) {if (count == K) ans = true;}
        else if (md > 0 && rest > 0) {if (rest % md == 0 && rest / md <= M) ans = true;}
        else if (md < 0 && rest < 0) {if (rest % md == 0 && rest / md <= M) ans = true;}
        if (ans) break;
    }
    ATYN(ans)

    return 0;
}