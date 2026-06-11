#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

template <typename T>
void print(const T &v);

int main()
{
    int X, Y;
    cin >> X >> Y;
    int a[4] = {1, 0, 1, 0};
    int b[4] = {1, 1, 0, 0};

    int mini = INF;
    for (int i = 0; i < 4; i++)
    {
        int x = X, y = Y;
        if (a[i])
            x *= -1;
        if (b[i])
            y *= -1;
        int tmp = y - x;
        if (tmp >= 0)
        {
            mini = min(tmp + a[i] + b[i], mini);
        }
    }
    cout << mini << endl;
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
