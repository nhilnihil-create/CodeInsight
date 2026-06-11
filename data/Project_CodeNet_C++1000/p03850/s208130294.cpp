# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;
# define fi cin
# define fo cout
# define x first
# define y second
# define ll long long
# define IOS ios_base :: sync_with_stdio(0);cin.tie(0)
# define p(v) cerr << #v << " = " << v << '\n'
# define p2(v) cerr << #v << " = " << (complex < int > (v.x,v.y)) << '\n'
# define vi vector < int >
# define vl vector < ll >
# define pii pair < int , int >
# define mp make_pair
# define db long double
# define pb push_back
# define pdd pair < db , db >
# define int ll
int32_t main(void)
{
    #ifdef CF
    freopen("input","r",stdin);
    #endif // CF
    srand(time(0));
    fo << fixed << setprecision(7);
    cerr << fixed << setprecision(7);
    int n;
    fi>>n;
    static int s[1 << 20];
    static char op[1 << 20];
    op[1] = '+';
    for (int i = 1;i <= n;++i)
    {
        fi>>s[i];
        if (i < n)
            fi>>op[i + 1];
    }
    static int ss[1 << 20];
    for (int i = 1;i <= n;++i)
        ss[i] = (op[i] == '-' ? -1 : 1) * s[i] + ss[i - 1];
    static int ab[1 << 20];
    for (int i = n;i;--i)
        ab[i] = ab[i + 1] + s[i];
    static int mn[1 << 20];
    for (int i = n;i;--i)
        mn[i] = op[i] == '+' ? mn[i + 1] : i;
    int ans = ss[n];
    for (int i = 0;i <= n;++i)
        if (op[i] == '-')
            ans = max(ans,ss[i - 1] - (-ab[mn[i + 1]] + ab[i]) + ab[mn[i + 1]]);
    fo << ans << '\n';
    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
    return 0;
}
