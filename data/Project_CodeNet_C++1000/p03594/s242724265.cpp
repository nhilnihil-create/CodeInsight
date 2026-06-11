#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair < int, int > PII;
typedef pair < LL, LL > PLL;
typedef pair < LD, LD > PDD;

#define _upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
template < typename _T > inline void _DBG(const char *s, _T x) { cerr << s << " = " << x << "\n"; }
template < typename _T, typename... args > void _DBG(const char *s, _T x, args... a) { while(*s != ',') cerr << *s++; cerr << " = " << x << ','; _DBG(s + 1, a...); }

#ifdef LOCAL
#define DBG(...) _DBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define DBG(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif

// ********************** CODE ********************** //

const int N = 1007;

int n, m, d;
PII ans[N][N];

int main()
{
    _upgrade
    cin >> n >> m >> d;
    for(int s = 0; s <= n + m - 2; s++)
    {
        for(int i = n - 1; i >= 0; i--)
        {
            int j = s - i;
            if(0 > j || j >= m) continue;
            ans[i][j].first = ((s / d) & 1);
        }
    }
    int rmn = 100001, rmx = -rmn;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            rmn = min(rmn, i - j), rmx = max(rmx, i - j);
    for(int r = rmx; r >= rmn; r--)
    {
        for(int i = 0; i <= n - 1; i++)
        {
            int j = i - r;
            if(0 > j || j >= m) continue;
            //ans[i][j].second = r;
            if(((r - rmn) / d) % 2 == 0) ans[i][j].second = 0;
            else ans[i][j].second = 1;
        }
    }

    /*
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << ans[i][j].first;
        }
        cout << "\n";
    }
    cout << "\n\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << ans[i][j].second;
        }
        cout << "\n";
    }
    cout << "\n\n";
    */
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(ans[i][j] == make_pair(0, 0)) cout << "R";
            if(ans[i][j] == make_pair(0, 1)) cout << "Y";
            if(ans[i][j] == make_pair(1, 0)) cout << "G";
            if(ans[i][j] == make_pair(1, 1)) cout << "B";
        }
        cout << "\n";
    }
	return 0;
}
