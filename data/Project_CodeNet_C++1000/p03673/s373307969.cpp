#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int n;
    cin >> n;
    ll a;
    deque<ll> b;
    if (n % 2 == 0)
    {
        rep(i, n)
        {
            cin >> a;
            if (i % 2 == 0)
            {
                b.push_back(a);
            }
            else
            {
                b.push_front(a);
            }
        }
    }
    else
    {
        rep(i, n)
        {
            cin >> a;
            if (i % 2 == 0)
            {
                b.push_front(a);
            }
            else
            {
                b.push_back(a);
            }
        }
    }
    for (ll n : b)
    {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
