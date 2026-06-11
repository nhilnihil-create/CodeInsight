#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

int main()
{
    int sx, sy;
    int tx, ty;
    cin >> sx >> sy >> tx >> ty;

    v<string> root(4);

    for (int i = 0; i < ty - sy; i++)
    {
        root[0].push_back('U');
        root[1].push_back('D');
    }

    for (int i = 0; i < tx - sx; i++)
    {
        root[0].push_back('R');
        root[1].push_back('L');
    }

    root[2].push_back('L');
    root[3].push_back('R');
    for (int i = 0; i < ty - sy + 1; i++)
    {
        root[2].push_back('U');
        root[3].push_back('D');
    }

    for (int i = 0; i < tx - sx + 1; i++)
    {
        root[2].push_back('R');
        root[3].push_back('L');
    }
    root[2].push_back('D');
    root[3].push_back('U');

    for (int i = 0; i < root.size(); i++)
        cout << root[i];

    cout << endl;

    return 0;
}