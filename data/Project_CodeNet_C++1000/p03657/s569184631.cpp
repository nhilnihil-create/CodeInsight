#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int a, b;
    cin >> a >> b;

    cout << ((a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) ? "Possible" : "Impossible") << "\n ";

    return 0;
}
