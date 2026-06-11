#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    string s;
    int k;
    cin >> s;
    cin >> k;

    for (char &c : s)
    {
        if (c == 'a')
            continue;
        int d = 26 - (c - 'a');
        if (d <= k)
        {
            c = 'a';
            k -= d;
        }
    }
    k %= 26;
    s[s.size() - 1] = s[s.size() - 1] + k;
    cout << s << endl;
}