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
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    if (sx <= gx && sy <= gy)
    {
        for (int i = 0; i < gx - sx; i++)
        {
            cout << 'R';
        }
        for (int i = 0; i < gy - sy; i++)
        {
            cout << 'U';
        }
        for (int i = 0; i < gx - sx; i++)
        {
            cout << 'L';
        }
        for (int i = 0; i < gy - sy; i++)
        {
            cout << 'D';
        }
        cout << 'D';
        for (int i = 0; i < gx - sx + 1; i++)
        {
            cout << 'R';
        }
        for (int i = 0; i < gy - sy + 1; i++)
        {
            cout << 'U';
        }
        cout << "LU";
        for (int i = 0; i < gx - sx + 1; i++)
        {
            cout << 'L';
        }
        for (int i = 0; i < gy - sy + 1; i++)
        {
            cout << 'D';
        }
        cout << 'R' << endl;
        return 0;
    }
    else if (sx >= gx && sy <= gy)
    {
        for (int i = 0; i < sx - gx; i++)
        {
            cout << 'L';
        }
        for (int i = 0; i < gy - sy; i++)
        {
            cout << 'U';
        }
        for (int i = 0; i < sx - gx; i++)
        {
            cout << 'R';
        }
        for (int i = 0; i < gy - sy; i++)
        {
            cout << 'D';
        }
        cout << 'D';
        for (int i = 0; i < sx - gx + 1; i++)
        {
            cout << 'L';
        }
        for (int i = 0; i < gy - sy + 1; i++)
        {
            cout << 'U';
        }
        cout << "RU";
        for (int i = 0; i < sx - gx + 1; i++)
        {
            cout << 'R';
        }
        for (int i = 0; i < gy - sy + 1; i++)
        {
            cout << 'D';
        }
        cout << 'L' << endl;
        return 0;
    }
    else if (sx <= gx && sy >= gy)
    {
        for (int i = 0; i < gx - sx; i++)
        {
            cout << 'R';
        }
        for (int i = 0; i < sy - gy; i++)
        {
            cout << 'D';
        }
        for (int i = 0; i < gx - sx; i++)
        {
            cout << 'L';
        }
        for (int i = 0; i < sy - gy; i++)
        {
            cout << 'U';
        }
        cout << 'U';
        for (int i = 0; i < gx - sx + 1; i++)
        {
            cout << 'R';
        }
        for (int i = 0; i < sy - gy + 1; i++)
        {
            cout << 'D';
        }
        cout << "LD";
        for (int i = 0; i < gx - sx + 1; i++)
        {
            cout << 'L';
        }
        for (int i = 0; i < sy - gy + 1; i++)
        {
            cout << 'U';
        }
        cout << 'R' << endl;
        return 0;
    }
    else if (sx >= gx && sy >= gy)
    {
        for (int i = 0; i < sx - gx; i++)
        {
            cout << 'L';
        }
        for (int i = 0; i < sy - gy; i++)
        {
            cout << 'D';
        }
        for (int i = 0; i < sx - gx; i++)
        {
            cout << 'R';
        }
        for (int i = 0; i < sy - gy; i++)
        {
            cout << 'U';
        }
        cout << 'U';
        for (int i = 0; i < sx - gx + 1; i++)
        {
            cout << 'L';
        }
        for (int i = 0; i < sy - gy + 1; i++)
        {
            cout << 'D';
        }
        cout << "RD";
        for (int i = 0; i < sx - gx + 1; i++)
        {
            cout << 'R';
        }
        for (int i = 0; i < sy - gy + 1; i++)
        {
            cout << 'U';
        }
        cout << 'L' << endl;
        return 0;
    }
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
