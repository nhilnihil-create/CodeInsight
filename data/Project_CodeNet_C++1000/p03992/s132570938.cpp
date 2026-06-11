#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    // start
    string s;
    cin >> s;
    rep(i, 4) cout << s.at(i);
    cout << " ";
    rep(i, 8) cout << s.at(i + 4);
    cout << endl;
    // end

    return 0;
}
