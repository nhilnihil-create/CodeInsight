#include <iostream>
using namespace std;
typedef long long ll;

ll rec(ll n, ll m){
    if(n % m == 0) return m * (2 * (n / m) - 1);
    return rec(m, n % m) + m * (2 * (n / m));
}

int main()
{
    ll n, x;
    cin >> n >> x;
    cout << n + rec(max(x, n - x), min(x, n - x)) << endl;
}