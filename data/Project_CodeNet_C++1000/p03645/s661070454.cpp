#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m, 0), b(m, 0);
    rep(i, m) cin >> a[i] >> b[i];
    vector<bool> stt(m, false), goal(m, false);
    rep(i, m)
    {
        if (a[i] == 1)
        {
            stt[b[i]] = true;
        }
    }
    rep(i, m)
    {
        if (b[i] == n)
        {
            if (stt[a[i]] == true)
            {
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}