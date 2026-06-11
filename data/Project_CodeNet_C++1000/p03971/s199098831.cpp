#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)

int n, a, b;
string s;
int main()
{
    cin >> n >> a >> b;
    int ans = 0, abr = 0;
    cin >> s;
    rep(i, 0, n)
    {
        if (s[i] == 'a')
        {
            if (ans < a + b)
            {
                cout << "Yes" << endl;
                ans++;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else if (s[i] == 'b')
        {
            if (ans < a + b && abr < b)
            {
                cout << "Yes" << endl;
                abr++;
                ans++;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
