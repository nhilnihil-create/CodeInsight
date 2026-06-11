#include <bits/stdc++.h>

using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ldouble = long double;
 
const ll inf = 1ll << 60;
const ll mod = (ll)1e9 + 7;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(s) cout << s;
#define println(s) cout << s << endl;
#define printd(s) cout << fixed << setprecision(10) << s << endl;

string res = "No";
ll sum = 0;

int main()
{
    ll n, m;
    cin >> n >> m;

    string a[n];
    string b[m];

    for (ll i = 0; i < n; i++)
    {
        string x;
        cin >> a[i];
    }

    
    for (ll i = 0; i < m; i++)
    {
        string x;
        cin >> b[i];
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {

            bool is = true;
            ll h, w;
            for (h = 0; h  < m; h++)
            {
                ll y = i + h;
                if (y >= n)
                {
                    is = false;
                    break;
                }

                for (w = 0; w  < m; w++)
                {
                    ll x = j + w;
                    if (x >= n)
                    {
                        is = false;
                        break;
                    }

                    if (a[y][x] != b[h][w])
                    {
                        is = false;
                    }
                }
            }


            if (is)
            {
                res = "Yes";
            }

        }
    }

    println(res);
}