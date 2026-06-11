#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rem(i, m, n) for (int i = m; i < (n); i++)
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

    string a, b;
    cin >> a >> b;
    if (a.size() > b.size())
        cout << "GREATER"
             << "\n";
    else if (a.size() < b.size())
        cout << "LESS"
             << "\n";
    else
    {
        rep(i, a.size())
        {
            if (strcmp(&a[i], &b[i]) > 0)
            {
                cout << "GREATER"
                     << "\n";
                return 0;
            }
            else if (strcmp(&a[i], &b[i]) < 0)
            {
                cout << "LESS"
                     << "\n";
                return 0;
            }
        }
        cout << "EQUAL"
             << "\n";
    }

    return 0;
}