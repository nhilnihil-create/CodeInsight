#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    string a, b, c;
    cin >> a >> b >> c;

    cout << ((a[a.size() - 1] == b[0] && b[b.size() - 1] == c[0]) ? "YES" : "NO") << '\n';
    return 0;
}
