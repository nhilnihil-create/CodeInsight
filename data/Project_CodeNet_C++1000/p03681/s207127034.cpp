#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll perm(ll n)
{
    return n == 1? 1 : (n*perm(n-1)) % (1000000007);
}

int main(void)
{
    ll n,m;
    cin >> n >> m;

    if (abs(n-m) == 0)
    {
        cout << (perm(n) * perm(n) * 2)% (1000000007) << endl;
    }
    else if (abs(n-m) == 1)
    {
        cout << (perm(n) * perm(m))% (1000000007) << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    
    return 0;
}
