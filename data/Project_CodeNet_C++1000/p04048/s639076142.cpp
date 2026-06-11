#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, m;

ll f(ll p, ll q)
{
    if(p == q) return 0;
    if(q >= p - q) return f(q, p - q) + p;
    else return 2 * q * (p / q - 1) + f(p - (q * (p / q - 1)), q);
}

int main()
{
    cin>>n>>m;
    cout<<f(n, n - m) + m;
    return 0;
}
