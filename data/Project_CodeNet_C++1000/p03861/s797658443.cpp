#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
    ll a, b, x;
    cin >> a >> b >> x;

    ll ans = b / x - (a - 1) / x;
    if (a == 0 && x >1)
    {
        ++ans;
    }
    cout << ans << endl;
}