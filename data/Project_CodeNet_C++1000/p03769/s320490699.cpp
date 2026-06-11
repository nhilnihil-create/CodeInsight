# include <bits/stdc++.h>

# define pb push_back
# define fr first
# define sc second
# define mk make_pair

using namespace std;

const int inf = 1000000000 + 7;
const int N = 310;

typedef long long ll;

ll n;
deque <ll> a;
vector <ll> d;

inline void solve()
{
    scanf("%lld", &n);

    while(n)
    {
        if(n % 2 == 1)
        {
            d.pb(1);
            n /= 2;
        }
        else
        {
            d.pb(0);
            n --;
        }
    }

    int c = 1;

    for(int i = d.size() - 1; i >= 0; i --)
    {
        if(d[i] == 1)
            a.pb(c);
        else
            a.push_front(c);
        c ++;
    }
    cout << a.size() * 2 << endl;
    for(int i = 0; i < a.size(); i ++)
        cout << a[i] << " ";
    for(int i = 1; i < c; i ++)
        cout << i << " ";
}

int tests = 1;

int main()
{
//    scanf("%d", &tests);

    while(tests --)
        solve();
}
