#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1001001001;
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
    // 偶数番目が正数になる
    ll bf_e = 0;
    ll cnt_e = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (bf_e + a[i] <= 0)
            {
                ll num; // 変化量
                num = 1 - bf_e - a[i];
                cnt_e += num;
                bf_e = 1;
            }
            else
            {
                bf_e = bf_e + a[i];
            }
        }
        else
        {
            if (bf_e + a[i] >= 0)
            {
                ll num; // 変化量
                num = bf_e + a[i] + 1;
                cnt_e += num;
                bf_e = -1;
            }
            else
            {
                bf_e = bf_e + a[i];
            }
        }
    }
    // 奇数番目が整数になる
    ll bf_o = 0;
    ll cnt_o = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 1)
        {
            if (bf_o + a[i] <= 0)
            {
                ll num; // 変化量
                num = 1 - bf_o - a[i];
                cnt_o += num;
                bf_o = 1;
            }
            else
            {
                bf_o = bf_o + a[i];
            }
        }
        else
        {
            if (bf_o + a[i] >= 0)
            {
                ll num; // 変化量
                num = bf_o + a[i] + 1;
                cnt_o += num;
                bf_o = -1;
            }
            else
            {
                bf_o = bf_o + a[i];
            }
        }
    }
    cout << min(cnt_o, cnt_e) << endl;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}
