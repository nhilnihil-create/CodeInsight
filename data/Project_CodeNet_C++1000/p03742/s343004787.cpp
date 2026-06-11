#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);

    ll x, y;
    cin >> x >> y;
    if (abs (x - y) <= 1)
        cout << "Brown\n";
    else
        cout << "Alice\n";
}