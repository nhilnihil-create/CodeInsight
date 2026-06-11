#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    string s;
    cin >> s;
    int b, e;
    b = 1e9;
    e = -1;
    int n = s.size();
    rep(i, n)
    {
        if (s[i] == 'A' && i < b)
        {
            b = i;
        }
        else if (s[i] == 'Z' && i > e)
        {
            e = i;
        }
    }
    cout << e - b + 1 << endl;
    return 0;
}