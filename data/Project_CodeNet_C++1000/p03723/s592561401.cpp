
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
#define SortAsc(c) std::sort(c.begin(), c.end())
#define SortDesc(c) std::sort(c.rbegin(), c.rend())
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

bool isAllEven(vector<ll> &x)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] % 2 == 1)
        {
            return false;
        }
    }

    return true;
}

string makeHash(vector<ll> &x)
{
    SortAsc(x);
    string h;
    h += to_string(x[0]) + "," + to_string(x[1]) + "," + to_string(x[2]);
    return h;
}

vector<ll> exchange(vector<ll> &x)
{
    vector<ll> n(3);

    n[0] = x[1] / 2 + x[2] / 2;
    n[1] = x[0] / 2 + x[2] / 2;
    n[2] = x[0] / 2 + x[1] / 2;

    return n;
}

int main()
{
    set<string> s;
    vector<ll> x(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> x[i];
    }

    int count = 0;

    while (isAllEven(x))
    {
        string h = makeHash(x);
        if (s.count(h))
        {
            cout << -1 << endl;
            return 0;
        }

        s.insert(h);

        x = exchange(x);
        count++;
    }

    cout << count << endl;
}