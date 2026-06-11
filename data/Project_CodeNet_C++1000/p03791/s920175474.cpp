/**
 *    author:  [itmo] enot.1.10
 *    created: 25.02.2017 14:58:10       
**/
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */

const int N = 2e5 + 10;
const int mod = 1e9 + 7;


int a[N];


int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    int n;
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);

    int bad = 0;
    int ok = 0;
    int res = 1;

    for (int i = 0; i < n; ++i)
    {
        int want = 2 * (i - bad) + 1;
        if (a[i] >= want)
        {
            ok++;
            continue;
        }
        bad++;
        res = (res * (ll)(ok + 1)) % mod;
    }
    for (int i = 1; i <= ok; ++i) res = (res * (ll)i) % mod;
    printf("%d\n", res);
        
            

    
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
