#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
int cnt = 0;
int main()
{
    string s;
    cin >> s;
    string s2 = "CODEFESTIVAL2016";
    rep(i, 0, 16)
    {
        if (s[i] != s2[i])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
