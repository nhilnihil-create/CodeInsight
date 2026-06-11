#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define repd(i, a, b) for (int i = a; i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
    int n;
    cin >> n;
    vector<int> s(n);
    int total = 0;
    rep(i, 0, n)
    {
        cin >> s[i];
        total += s[i];
    }
    sort(all(s));
    if (total % 10 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (((total - s[i]) % 10) == 0)
                continue;
            else
            {
                total -= s[i];
                break;
            }
        }
    }
    if (total % 10 == 0)
        cout << 0 << endl;
    else
        cout << total << endl;
}
