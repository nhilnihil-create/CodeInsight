#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;
#define fast() ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define digit(N) cout << fixed << setprecision((N))

bool is_unbalanced(string s)
{
    map<char, int> mp;
    int sz = s.size();
    if (sz < 2)
        return false;
    for (int i = 0; i < sz; i++)
    {
        mp[s[i]]++;
    }

    for (auto &c : mp)
    {
        if (2 * c.second > sz)
            return true;
    }
    return false;
}

string s;

int main()
{
    cin >> s;
    int N = s.size();
    for (int i = 0; i + 1 < N; i++)
    {
        string t = s.substr(i, 2);
        if (is_unbalanced(t))
        {
            cout << i + 1 << " " << i + 2 << "\n";
            return 0;
        }
    }
    if (N == 2)
    {
        cout << -1 << " " << -1 << endl;
        return 0;
    }

    for (int i = 0; i + 2 < N; i++)
    {
        string t = s.substr(i, 3);
        if (is_unbalanced(t))
        {
            cout << i + 1 << " " << i + 3 << "\n";
            return 0;
        }
    }

    cout << -1 << " " << -1 << endl;
}
