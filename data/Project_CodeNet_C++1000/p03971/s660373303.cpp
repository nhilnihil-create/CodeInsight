#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

//read question carefully!

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'a')
            {
                if (a + b > 0)
                {
                    cout << "Yes"
                         << "\n";
                    a--;
                }
                else
                {
                    cout << "No"
                         << "\n";
                }
            }
            else if (s[i] == 'b')
            {
                if (a + b > 0 && b > 0)
                {
                    cout << "Yes"
                         << "\n";
                    b--;
                }

                else
                {
                    cout << "No"
                         << "\n";
                }
            }
            else
            {
                cout << "No"
                     << "\n";
            }
        }
    }
}