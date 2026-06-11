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
# define vll vector < ll >
# define pii pair < int , int >
# define mp make_pair
# define db long double
# define pdd pair < db , db >
int main(void)
{
    #ifdef CF
    freopen("input","r",stdin);
    #endif // CF
    srand(time(0));
    fo << fixed << setprecision(7);
    cerr << fixed << setprecision(7);
    int n,m;
    fi>>n>>m;
    static int cnt[1 << 20];
    static map < int , int > s[1 << 20];
    int v;
    for (int i = 1;i <= n;++i)
        fi>>v,s[v % m][v]++,cnt[v % m]++;;
    ll ans = 0;
    for (int i = 0;i + i <= m;++i)
    {
        int a = i;
        int b = (m - i) % m;
        if (a == b)
            ans += cnt[i] / 2;
        else
        {
            if (cnt[a] < cnt[b]) swap(a,b);
            for (auto &it : s[a])
                if ((it.y & 1) && cnt[b])
                    --cnt[a],--cnt[b],++ans,--it.y;
            for (auto &it : s[a])
            {
                int can = min(cnt[b],it.y);
                cnt[b] -= can;
                it.y -= can;
                ans += can;
                ans += it.y / 2;
            }
        }
    }
    fo << ans << '\n';
    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
    return 0;
}


