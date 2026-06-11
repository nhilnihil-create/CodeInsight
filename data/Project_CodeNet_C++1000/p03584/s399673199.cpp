#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <tuple>
#include <cassert>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mp(a,b) make_pair((a), (b))
#define mt(a,b,c) make_tuple((a),(b),(c))

typedef long long ll;

void PrintBitC(int c)
{
    int bit = 1 << 30;
    while (bit != 0)
    {
        if (c & bit)
            putchar('1');
        else
            putchar('0');
        bit >>= 1;
    }
    putchar('\n');
}


int main(){
    int n,k; cin >> n >> k;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    ll ans = 0;
    rep(i,n) if((~k & a[i]) == 0) ans += b[i]; 
    for(int i=1;i<30;i++){
        if((1<<i & k) == (1<<i)){
            int tk = (~(1<<i) & k) | ((1<<i) - 1);
           // PrintBitC(tk);
            ll ta = 0;
            rep(j,n){
                if((~tk & a[j]) == 0) ta += b[j];
            }
            ans = max(ans, ta);
        }
    }
    cout << ans << endl;
    return 0;
}