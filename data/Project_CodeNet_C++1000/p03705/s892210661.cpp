#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (i = a; i < b; i++)
#define REP_ITER(it, v) for (it = v.begin(); it != v.end(); it++)

#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0)

#define TEST(test) \
    int test;      \
    cin >> test;   \
    while (test--)

#define cll(a, b) cin >> a >> b
#define YES cout << "YES\n"
#define NO cout << "NO\n"

#define vi vector<int>
#define vi_iterator vector<int>::iterator

#define si set<int>
#define si_iterator set<int>::iterator

double pi = 2 * acos(0.0);
int i, j;
int main()
{
    FASTIO;
    ll n, a, b;
    cin >> n >> a >> b;
    if (n < 2 && a != b)
    {
        cout << 0 << endl;
    }
    else if (n < 2 && a == b)
    {
        cout << 1 << endl;
    }
    else if (n == 2 && a <= b)
    {
        cout << 1 << endl;
    }
    else if (n == 2 && a > b)
    {
        cout << 0 << endl;
    }
    else if (a > b)
    {
        cout << 0 << endl;
    }
    else
    {
        ll diff = (b * (n - 2) - a * (n - 2)) + 1;
        cout << diff << endl;
    }
}