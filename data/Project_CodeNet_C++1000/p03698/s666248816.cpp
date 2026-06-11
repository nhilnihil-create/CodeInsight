#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    string s;
    cin >> s;
    set<char> st;
    bool ok = true;
    rep(i, s.size())
    {
        if (st.count(s[i]))
        {
            ok = false;
            break;
        }
        else
            st.insert(s[i]);
    }
    if (ok)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}

int main()
{
    solve();
    return 0;
}