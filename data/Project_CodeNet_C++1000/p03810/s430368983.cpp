# include <bits/stdc++.h>

# define pb push_back
# define fr first
# define sc second
# define mk make_pair

using namespace std;

const int inf = 1000000000 + 7;
const int N = 1e5 + 5;

typedef int ll;

ll n, odd, ar[N], cnt;

ll calc(ll player)
{
    ll cn = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(ar[i] % 2 == 0)
            cn ++;
        if(ar[i] & 1) odd = i;
    }
    if(cn % 2) return player;

    if(cn + 1 < n) return player ^ 1;

    if(ar[odd] == 1) return player ^ 1;

    ar[odd] --;

    ll gcd = 0;

    for(int i = 1; i <= n; i ++)
    {
        gcd = __gcd(gcd, ar[i]);
    }

    for(int i = 1; i <= n; i ++)
        ar[i] /= gcd;

    calc(player ^ 1);
}

inline void solve()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i ++)
    {
        scanf("%d", &ar[i]);
    }

    if(calc(1)) cout << "First" << endl;
    else cout << "Second" << endl;
}

int tests = 1;

int main()
{
//    scanf("%d", &tests);

    while(tests --)
        solve();
}
