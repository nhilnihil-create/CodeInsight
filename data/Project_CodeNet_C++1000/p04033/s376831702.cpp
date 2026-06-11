#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;

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

int main()
{
    ll a, b;
    cin >> a >> b;

    if (a > 0 && b > 0)
    {
        cout << "Positive" << endl;
        return 0;
    }
    if (max(a, b) >= 0 && min(a, b) <= 0)
    {
        cout << "Zero" << endl;
        return 0;
    }
    if ((max(a, b) - min(a, b)) % 2 == 0)
    {
        cout << "Negative" << endl;
    }
    else
    {
        cout << "Positive" << endl;
    }
    return 0;
}
