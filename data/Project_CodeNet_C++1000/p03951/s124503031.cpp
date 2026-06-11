#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Yes                \
    cout << "Yes" << endl; \
    return 0;
#define No                \
    cout << "No" << endl; \
    return 0;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

template <typename T>
void print(const T &v);

int main()
{
    int N;
    string s, t;
    cin >> N >> s >> t;
    int cnt = 0;

    for (int i = 1; i <= N; i++)
    {
        string before, after;
        for (int j = 0; j < i; j++)
        {
            before.push_back(s[N - 1 - j]);
            after.push_back(t[j]);
        }
        reverse(before.begin(), before.end());
        if (before == after)
        {
            cnt = i;
        }
    }
    cout << 2 * N - cnt << endl;
    return 0;
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
