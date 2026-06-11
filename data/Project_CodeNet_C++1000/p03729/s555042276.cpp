#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout << ((f) ? "Yes" : "No") << endl
#define YORN(f) cout << ((f) ? "YES" : "NO") << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    YORN(a[a.size() - 1] == b[0] && b[b.size() - 1] == c[0]);
    return 0;
}