#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;
 
int main()
{
    int n, k;
    cin >> n >> k;
    vector<char> D;
    rep(i, k)
    {
        char a;
        cin >> a;
        D.push_back(a);
    }
 
    ll ans = n;
    while (1)
    {
        string s = to_string(ans);
        int flag = 1;
        rep(i, s.length())
        {
            for (auto d : D)
            {
                if (d == s[i])
                    flag = 0;
            }
        }
        if (flag)
        {
            cout << ans << endl;
            return 0;
        }
        ans++;
    }
}
#include <bits/stdc++.h>
using namespace std;