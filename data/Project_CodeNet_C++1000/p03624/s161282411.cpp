#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

int main()
{
    string s;
    cin >> s;
    vector<int> ck(26, 0);
    int ans = 1001001001;
    rep(i, s.size()) ck[s[i] - 'a']++;

    rep(i, 26)
    {
        if (ck[i] == 0)
        {
            cout << (char)(i + 'a') << endl;
            return (0);
        }
    }
    cout << "None" << endl;
    return (0);
}
