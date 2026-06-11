#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n;
    string s, t;
    cin >> n >> s >> t;

    int i = 0;
    while (i < n)
    {
        string a = s.substr(i);
        string b = t.substr(0, n - i);
        if (a == b)
            break;

        i++;
    }

    cout << 2 * n - (n - i) << endl;
}