#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
using namespace std;

#define ll long long int
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define repm(i, a, n) for (ll i = a; i >= n; i--)
#define INF 1e9
#define LINF 1e17
#define MOD (int)(1e9 + 7)
#define pi 3.141592653589
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vii vector<vector<int>>
#define vll vector<ll>
#define vllll vector<vector<ll>>
#define ALL(a) (a).begin(), (a).end()
#define sort_v(a) sort(a.begin(), a.end())
#define reverse_v(a) reverse(a.begin(), a.end())
#define fi first
#define se second

void print(bool c)
{
    (c) ? (cout << "Yes" << endl) : (cout << "No" << endl);
}

void Print(bool c)
{
    (c) ? (cout << "YES" << endl) : (cout << "NO" << endl);
}

//最小公倍数
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

//最大公約数
template <typename T>
T lcm(T a, T b)
{
    return a * b / gcd(a, b);
}
//セカンドキー->ファーストキーの順ソート
bool cmp(const pii &a, const pii &b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

int eve(int x)
{
    if (x % 400 == 0)
        return 1;
    if (x % 100 == 0)
        return 0;
    if (x % 4 == 0)
        return 1;
    return 0;
}

int main(void)
{
    string s;
    cin >> s;
    set<char> mp;
    for (auto c : s)
        mp.insert(c);
    if (mp.size() == 1)
        return cout << 0 << endl, 0;
    int ans = INF;
    for (auto x : mp)
    {
        //cout << x << endl;
        string t = s;
        int cnt = 0;
        while (1)
        {
            bool f = true;
            string tmp;
            rep(i, 0, t.size() - 1)
            {
                if (t[i] == x || t[i + 1] == x)
                    tmp += x;
                else
                    tmp += t[i], f = false;
            }
            //cout << tmp << endl;
            cnt++;
            if (f)
                break;
            t = tmp;
        }
        ans = min(ans, cnt);
        //cout << ans << endl;
    }
    cout << ans << endl;
}
