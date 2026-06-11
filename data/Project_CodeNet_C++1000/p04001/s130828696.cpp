#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; ++i)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;

    int n;
    ll sum;
    n = sum = 0;
    n = s.size() - 1;

    for (int bit = 0; bit < (1 << n); bit++)
    {
        int pos = s.size();
        int num = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            pos--;
            num++;

            if (bit & (1 << i))
            {
                sum += stoll(s.substr(pos, num));
                num = 0;
            }
        }
        sum += stoll(s.substr(pos, num));
    }
    cout << sum << endl;

    return 0;
}
