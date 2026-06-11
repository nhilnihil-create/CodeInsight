#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define int long long int
#define double long double
#define inf (int)(1e15)
#define all(x) (x).begin(), (x).end()
#define pair pair<int, int>
typedef vector<int> vi;   // Vector of long long
typedef vector<vi> vvi;   // Vector of vi
typedef vector<pair> vii; // Vector of pairs
typedef vector<vii> vvii; // Vector of Vector of pairs
typedef vector<bool> vb;  // Vector of bool
#define pq priority_queue // Max heap (To convert to min heap, use negative sign before every value)
#define ff first          // For pairs
#define ss second
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, -1, 0, 1};
const int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}, dy8[] = {1, -1, 1, 0, -1, 1, -0, -1};
#define testcases(t) \
    int(t);          \
    cin >> (t);      \
    while ((t)--)
signed main()
{
    int h, w;
    char a;
    vi cnt(30, 0);
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> a;
            cnt[a - 'a']++;
        }
    }
    int g1, g2, g4;
    if (h % 2 == 0 && w % 2 == 1)
        swap(h, w);
    if (h % 2 && w % 2)
    {
        g1 = 1;
        g2 = (h + w) / 2 - 1;
        g4 = (h - 1) * (w - 1) / 4;
    }
    else if (h % 2 && w % 2 == 0)
    {
        g1 = 0;
        g2 = w / 2;
        g4 = (h - 1) * w / 4;
    }
    else
    {
        g1 = 0;
        g2 = 0;
        g4 = (h * w) / 4;
    }
    int flag = 0;
    while (g4)
    {
        int old = g4, latest = g4;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] >= 4)
            {
                latest--;
                cnt[i] -= 4;
            }
        }
        if (latest == old)
        {
            flag = 1;
            break;
        }
        else
            g4 = latest;
    }
    while (g2)
    {
        int old = g2, latest = g2;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] >= 2)
            {
                latest--;
                cnt[i] -= 2;
            }
        }
        if (latest == old)
        {
            flag = 1;
            break;
        }
        else
            g2 = latest;
    }
    while (g1)
    {
        int old = g1, latest = g1;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] >= 1)
            {
                latest--;
                cnt[i]--;
            }
        }
        if (latest == old)
        {
            flag = 1;
            break;
        }
        else
            g1 = latest;
    }
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i])
            flag = 1;
    }
    if (flag)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    return 0;
}