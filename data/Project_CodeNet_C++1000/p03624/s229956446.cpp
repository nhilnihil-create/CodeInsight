#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    string s;
    cin >> s;
    vector<int> alpha(26, 0);

    string ans = "None";
    int n = s.size();
    rep(i, n)
    {
        int num = s[i] - 'a';
        alpha[num]++;
    }

    rep(i, 26)
    {
        if (alpha[i] == 0)
        {
            ans = char(i + 'a');
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
