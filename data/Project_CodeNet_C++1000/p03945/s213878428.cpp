#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    bool lb = s[0] == 'B';
    for (int i = 1; i < (int)s.size(); i++)
    {
        if ((s[i] == 'B') != lb)
        {
            ans++;
            lb = !lb;
        }
    }
    cout << ans << endl;
}
