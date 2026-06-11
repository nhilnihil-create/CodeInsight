#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    ll a, b, x;
    cin >> a >> b >> x;
    
    ll nb = 1 + b / x;
    ll na = a <= 0 ? 0 : 1 + (a - 1) / x;
    put(nb - na)
    return 0;
}