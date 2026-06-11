#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int MOD = 1e9 + 7;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

//-------------------ここから回答する-----------------------

void solve(void)
{
    string sa, sb, sc;
    cin >> sa >> sb >> sc;

    deque<char> da, db, dc;
    for (auto i : sa)
        da.emplace_back(i);
    for (auto i : sb)
        db.emplace_back(i);
    for (auto i : sc)
        dc.emplace_back(i);

    char st = 'a';

    while (true)
    {

        if (st == 'a')
        {
            if (da.size() == 0)
            {
                cout << "A" << endl;
                return;
            }
            st = da.front(), da.pop_front();
        }
        else if (st == 'b')
        {
            if (db.size() == 0)
            {
                cout << "B" << endl;
                return;
            }
            st = db.front(), db.pop_front();
        }
        else if (st == 'c')
        {
            if (dc.size() == 0)
            {
                cout << "C" << endl;
                return;
            }
            st = dc.front(), dc.pop_front();
        }
    }
}
int main(void)
{
    solve();
}
