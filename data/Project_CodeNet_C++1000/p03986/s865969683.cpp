#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;
const int MOD = 1'000'000'007;

template <typename T>
void print(const T &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    string x;
    cin >> x;
    int s_cnt = 0;
    int len = x.size();
    for (char c : x)
    {
        if (c == 'S')
        {
            ++s_cnt;
        }
        else
        {
            if (s_cnt > 0)
            {
                --s_cnt;
                len -= 2;
            }
        }
    }
    cout << len << endl;
    return 0;
}
