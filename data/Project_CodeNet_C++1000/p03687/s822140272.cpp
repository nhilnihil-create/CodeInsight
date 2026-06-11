#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for (int i = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define MP make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int MOD = 1e9 + 7;

int main()
{
    string S;
    cin >> S;
    int res = INF;

    for (int i = 0; i < 26; i++)
    {
        char target = (char)('a' + i);
        string T = S;
        int cnt = 0;
        bool isAll = 1;
        rep(i, T.size()) if (T[i] != target) isAll = false;
        if (isAll)
        {
            cout << 0 << endl;
            return 0;
        }
        while (1)
        {
            string new_T = "";
            for (int j = 0; j < T.size() - 1; j++)
            {
                if (T[j] == target || T[j + 1] == target)
                {
                    new_T.pb(target);
                }
                else
                {
                    new_T.pb('*');
                }
            }
            cnt++;
            bool ok = 1;
            for (int j = 1; j < new_T.size(); j++)
            {
                if (new_T[j] != new_T[j - 1])
                    ok = 0;
            }
            if (ok)
            {
                if (new_T[0] == target)
                {
                    res = min(cnt, res);
                }
                break;
            }
            T = new_T;
        }
    }
    cout << res << endl;
    return 0;
}