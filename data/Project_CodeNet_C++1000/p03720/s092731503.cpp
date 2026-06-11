#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        v[a - 1]++;
        v[b - 1]++;
    }

    rep(i, n)
    {
        cout << v[i] << endl;
    }
    return (0);
}
