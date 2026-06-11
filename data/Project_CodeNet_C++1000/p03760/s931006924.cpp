#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string O, E;
    cin >> O >> E;
    int n = O.size(), m = E.size();

    for (int i = 0; i < m; ++i)
    {
        cout << O[i] << E[i];
    }
    if (n > m)
        cout << O[n - 1];
    cout << '\n';

    return 0;
}