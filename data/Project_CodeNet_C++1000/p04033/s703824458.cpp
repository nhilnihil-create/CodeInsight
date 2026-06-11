#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repm(i, m, n) for (int i = m; i < (n); i++)
#define eps (1e-7)
#define inf (1e9)
#define pi (acos(-1))
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    //true -> pos, false -> neg
    //bool sign = true;

    if ((a <= 0 && 0 <= b))
    {
        cout << "Zero" << endl;
    }
    else if (0 < a || (abs(b) - abs(a) + 1) % 2 == 0)
    {
        cout << "Positive" << endl;
    }
    else
        cout << "Negative" << endl;

    return 0;
}