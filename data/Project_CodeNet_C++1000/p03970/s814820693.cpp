#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)

int main()
{
    string s;
    const string ans = "CODEFESTIVAL2016";
    cin >> s;
    int out = 0;
    for (int i = 0; i < ans.length(); ++i)
    {
        if (s[i] != ans[i])
        {
            out++;
        }
    }
    cout << out << endl;
}