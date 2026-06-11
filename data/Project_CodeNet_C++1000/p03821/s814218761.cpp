#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <algorithm>
//#include <ctype.h>
#include <vector>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
using namespace std;

#define ll long long int
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repm(i, a, n) for (int i = a; i >= n; i--)
#define INF 1e9
#define LINF 1e17
#define MOD (int)(1e9 + 7)
#define pi 3.141592653589
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vs vector<string>
#define vii vector<vector<int>>
#define vll vector<ll>
#define vllll vector<vector<ll>>
#define vd vector<double>
#define ALL(a) (a).begin(), (a).end()
#define sort_v(a) sort(a.begin(), a.end())
#define fi first
#define se second

void print(bool c)
{
    if (c)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

void Print(bool c)
{
    if (c)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

template <typename T>
T gcd(T a, T b)
{
    while (1)
    {
        if (a < b)
            swap(a, b);
        if (b == 0)
            break;
        a %= b;
    }
    return a;
}

template <typename T>
T lcm(T a, T b)
{
    return a * b / gcd(a, b);
}

bool cmp(const pii &a, const pii &b) //セカンドキー->ファーストキーの順ソート
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    int n;
    cin >> n;
    vll a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];

    ll ans = 0;
    repm(i, n - 1, 0)
    {
        //cout << ans << " " << ((a[i] + ans - 1) / b[i] + 1) * b[i] << endl;
        if ((a[i] + ans) % b[i])
            ans += b[i] - (a[i] + ans) % b[i];
    }
    cout << ans << endl;
}