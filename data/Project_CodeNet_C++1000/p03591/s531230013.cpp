#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    // start
    char y[4] = {'Y', 'A', 'K', 'I'};
    rep(i, 4)
    {
        char s;
        cin >> s;
        if (s != y[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    // end

    return 0;
}
