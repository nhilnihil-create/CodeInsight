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

string res;
ll sum = 0;

int main()
{
    ll a, b;
    cin >> a >> b;

    if (a == 1)
    {
        a = 14;
    }

    if (b == 1)
    {
        b = 14;
    }

    if (a > b)
    {
        println("Alice");
    }
    else if (a < b)
    {
        println("Bob");
    }
    else
    {
        
        println("Draw");
    }
    
}
