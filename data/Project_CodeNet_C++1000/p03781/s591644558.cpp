#include <bits/stdc++.h>

const int N = 100005;

using namespace std;
typedef long long ll;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(x) (x).begin(), (x).end()


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int x = 0;
    for (int i = 1; ; i++)
    {
        x += i;
        if (x >= n) cout << i, exit(0);
    }
}
