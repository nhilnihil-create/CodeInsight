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
    int a, b;
    cin >> a >> b;
    if (a + b >= 10)
        cout << "error" << endl;
    else
        cout << a + b << endl;
}
