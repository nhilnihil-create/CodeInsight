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
    string s;
    cin >> s;
    sort(all(s));
    bool diff = 1;
    for (int i = 1; i < sz(s); i++)
    {
        if (s[i] == s[i - 1])
        {
            diff = 0;
            break;
        }
    }
    if (diff)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
