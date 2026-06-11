#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b < c)
        puts("0");
    else if (d < a)
        puts("0");
    else
    {
        vector<int> s = {a, b, c, d};
        sort(s.begin(), s.end());
        cout << s[2] - s[1];
    }
}