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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(3 * n);
    for (int i = 0; i < 3 * n; i++)
    {
        cin >> a[i];
    }
    // 左からを考える
    vector<ll> left(2 * n + 1, 0); //累積和
    priority_queue<ll, vector<ll>, greater<ll>> queL;
    for (int i = 0; i < n; i++)
    {
        left[i + 1] = left[i] + a[i];
        queL.push(a[i]);
    }
    for (int i = n; i < 2 * n; i++)
    {
        ll tp = queL.top();
        if (a[i] > tp)
        {
            left[i + 1] = left[i] - tp + a[i];
            queL.pop();
            queL.push(a[i]);
        }
        else
        {
            left[i + 1] = left[i];
        }
    }
    // 右からを考える
    vector<ll> right(2 * n + 1, 0);
    priority_queue<ll> queR;
    for (int i = 0; i < n; i++)
    {
        right[i + 1] = right[i] + a[3 * n - i - 1];
        queR.push(a[3 * n - i - 1]);
    }
    for (int i = n; i < 2 * n; i++)
    {
        ll tp = queR.top();
        if (tp > a[3 * n - i - 1])
        {
            right[i + 1] = right[i] - tp + a[3 * n - i - 1];
            queR.pop();
            queR.push(a[3 * n - i - 1]);
        }
        else
        {
            right[i + 1] = right[i];
        }
    }
    ll ans = -LLINF;
    for (int i = n; i <= 2 * n; i++)
    {
        chmax(ans, left[i] - right[3 * n - i]);
    }
    cout << ans << endl;
}