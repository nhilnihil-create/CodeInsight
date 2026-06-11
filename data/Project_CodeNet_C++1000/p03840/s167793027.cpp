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
    std::vector<ll> v(7);
    REP(i,7) cin >> v[i];
    
    ll ans = 0;
    ans += v[0] / 2 * 2;
    ans += v[1] ;
    ans += v[3] / 2 * 2;
    ans += v[4] / 2 * 2;
    
    int LIJ = 0;
    LIJ += v[0] % 2 == 1; 
    LIJ += v[3] % 2 == 1; 
    LIJ += v[4] % 2 == 1;
    if (v[0] == 0 || v[3] == 0 || v[4] == 0) LIJ = 0;
    if (LIJ == 2) ans +=1;
    if (LIJ == 3) ans +=3;
    
    cout << ans << endl;

    return 0;
}