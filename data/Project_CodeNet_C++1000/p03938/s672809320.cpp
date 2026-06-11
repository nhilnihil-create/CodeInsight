#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define EPS (1e-7)
#define INF (1 << 30)
#define LLINF (1LL << 60)
#define PI (acos(-1))
#define MOD (1000000007)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

const int m = 40000;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = m * (i + 1);
        b[i] = m * (n - i - 1) + 1;
    }
    for (int i = 0; i < n; i++)
    {
        a[p[i] - 1] += i;
    }
    for (auto ans : a)
    {
        cout << ans << ' ';
    }
    cout << endl;
    for (auto ans : b)
    {
        cout << ans << ' ';
    }
    cout << endl;
}