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

// const int MAX = 1010;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    for (int left = 0; left < 101; left++)
    {
        for (int right = 0; right < 101; right++)
        {
            string l_str(left, '(');
            string r_str(right, ')');
            string str = l_str + s + r_str;
            int cnt = 0;
            for (char cc : str)
            {
                if (cc == '(')
                {
                    ++cnt;
                }
                else
                {
                    --cnt;
                    if (cnt < 0)
                    {
                        break;
                    }
                }
            }
            if (cnt == 0)
            {
                cout << str << endl;
                return 0;
            }
        }
    }
}