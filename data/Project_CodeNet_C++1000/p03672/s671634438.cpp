#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string S;
    cin >> S;

    int ans;
    for (int i = 1; i < S.size(); i++)
    {
        int length = (S.size() - i);
        if (length % 2 != 0)
        {
            continue;
        }
        if (S.substr(0, length / 2) == S.substr(length / 2, length / 2))
        {
            ans = length;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}