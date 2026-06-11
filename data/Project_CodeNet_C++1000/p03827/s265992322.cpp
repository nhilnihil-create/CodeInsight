#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    int n;
    string s;
    cin >> n >> s;
    int x = 0;
    int max = 0;
    rep(i, n)
    {
        if (s[i] == 'I')
        {
            x++;
        }
        else if (s[i] == 'D')
        {
            x--;
        }
        if (x > max)
        {
            max = x;
        }
    }
    cout << max << endl;

    return 0;
}
