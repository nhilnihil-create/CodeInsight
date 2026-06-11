#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    int i;
    int turn = 0;
    int idx[3] = {0, 0, 0};
    string s[3];
    rep(i, 3) cin >> s[i];

    while (1)
    {
        if (s[turn].length() == idx[turn])
        {
            cout << (char)('A' + turn) << endl;
            break;
        }
        idx[turn] += 1;
        turn = s[turn][idx[turn] - 1] - 'a';
    }

    return 0;
}
