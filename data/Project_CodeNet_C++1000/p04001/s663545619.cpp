#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    ll ans = 0;
    rep(i, 1 << s.size())
    {
        bitset<10> b(i);
        string ns;
        rep(j, s.size())
        {
            ns += s[j];
            if (b.test(j))
            {
                ns += '+';
            }
        }
        //cout << ns << endl;
        string nns;
        if (ns[ns.size() - 1] != '+')
        {
            rep(j, ns.size())
            {
                if (ns[j] == '+')
                {
                    ans += stoll(nns);
                    nns = "";
                }
                else
                    nns += ns[j];
            }
            ans += stoll(nns);
            //cout << ans << endl;
        }
    }
    cout << ans << endl;
}
