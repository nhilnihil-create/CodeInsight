#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    //コーナーケースの処理
    if (n == 1 && a != b)
    {
        cout << 0 << endl;
    }
    else if (a == b)
    {
        cout << 1 << endl;
    }
    else if (a > b)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << (a + b * (n - 1)) - (a * (n - 1) + b) + 1 << endl;
    }
}