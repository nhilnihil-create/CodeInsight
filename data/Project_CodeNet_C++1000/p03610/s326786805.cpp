#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int count(int n)
{
    int cnt = 0;
    while (n / 2)
    {
        cnt++;
        n /= 2;
    }
    return cnt;
}

int main()
{
    string s;
    cin >> s;

    rep(i, s.size())
    {
        if (!(i & 1))
        {
            cout << s[i];
        }
    }

    cout << endl;
    return 0;
}
