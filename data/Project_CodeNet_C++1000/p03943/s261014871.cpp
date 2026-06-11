#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b == c || a + c == b || b + c == a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}