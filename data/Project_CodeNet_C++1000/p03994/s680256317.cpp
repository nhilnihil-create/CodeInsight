#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int k;

    cin >> s >> k;

    int n = s.length();

    vector <int> c(n, 0);

    for (int i = 0; i < n; i++)
    {
        c[i] = ('z' - s[i] + 1) % 26;
    }

    for (int i = 0; i < n; i++)
    {
        if (c[i] <= k)
        {
            s[i] = 'a';
            k -= c[i];
        }
    }

    k = k % 26;
    s[n-1] = ((s[n-1] - 'a' + k) % 26) + 'a';

    cout << s << "\n";

    return 0;
}