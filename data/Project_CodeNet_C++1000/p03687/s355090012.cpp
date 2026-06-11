#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

bool isSame(const string s, const char c)
{
    bool res = true;
    REP(i, s.size())
    {
        if (s[i] != c)
        {
            res = false;
            break;
        }
    }

    return res;
}

int main()
{
    string s;
    cin >> s;
    set<char> candC;
    REP(i, s.size())
    {
        candC.insert(s[i]);
    }

    ll ans = LONG_MAX;
    REPV(it, candC)
    {
        char c = *it;
        bool flag = true;
        if (isSame(s, c))
        {
            ans = 0;
            break;
        }

        string copyS(s);
        ll count = 0;
        while(copyS.size() > 0)
        {
            REP(i, copyS.size() - 1)
            {
                if (copyS[i] == c || copyS[i + 1] == c)
                {
                    copyS[i] = c;
                }
            }
            count++;
            copyS.pop_back();
            if (isSame(copyS, c))
            {
                ans = min(ans, count);
                break;
            }
        }
    }

    cout << ans << endl;
}
