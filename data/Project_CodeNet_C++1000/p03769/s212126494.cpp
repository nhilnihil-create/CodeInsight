/**
 *    author:  [itmo] enot.1.10
 *    created: 03.04.2017 20:33:55       
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

const int N = 222;


int a[N];



int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    ll n;
    scanf("%lld", &n);
    /*if (n <= 100)
    {
        printf("%lld\n", 2 * n);
        forn(i, n) printf("%d %d%c", i + 1, i + 1, " \n"[i + 1 == n]);
        return 0;
    } */
    int last = 0;
    vi res;

    vi path;
    while (n > 0)
    {
        if (n & 1)
        {
            path.pb(2);
            n >>= 1;
        }
        else
        {
            path.pb(1);
            n -= 1;
        }
    }

    reverse(all(path));
    for (int x : path)
    {
        if (x == 1)
        {
            res.insert(res.begin(), ++last);
        }
        else
        {
            res.push_back(++last);
        }
    }

    printf("%d\n", 2 * last);
    forn(i, last) printf("%d ", i + 1);
    forn(i, last) printf("%d%c", res[i], " \n"[i + 1 == last]);
        
            
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
