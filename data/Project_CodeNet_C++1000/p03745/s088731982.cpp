#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int mode = 0; // 0:平坦，1:上り，2:下り
    ll before = a[0];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (mode == 0)
        {
            if (before < a[i])
            {
                mode = 1;
            }
            else if (before > a[i])
            {
                mode = 2;
            }
            else
            {
                mode = 0;
            }
        }
        else if (mode == 1)
        {
            if (before > a[i])
            {
                ++cnt;
                mode = 0;
            }
        }
        else
        {
            if (before < a[i])
            {
                ++cnt;
                mode = 0;
            }
        }
        before = a[i];
    }
    cout << cnt << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
};