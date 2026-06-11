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
    string s;
    cin >> s;
    set<char> cs;
    for (char c : s)
    {
        cs.insert(c);
    }
    if (cs.size() == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    int mini = 100;
    for (char c : cs)
    {
        string now = s;
        int n = now.size();
        while (n != 0)
        {
            string next(n - 1, '.');
            --n;
            for (int i = 0; i < n; i++)
            {
                if (now[i] == c || now[i + 1] == c)
                {
                    next[i] = c;
                }
            }
            bool flag = true;
            for (int i = 0; i < n - 1; i++)
            {
                if (next[i] != next[i + 1])
                {
                    flag = false;
                }
            }
            if (flag)
            {
                mini = min(mini, (int)s.size() - n);
                break;
            }
            now = next;
        }
    }
    cout << mini << endl;
    return 0;
}