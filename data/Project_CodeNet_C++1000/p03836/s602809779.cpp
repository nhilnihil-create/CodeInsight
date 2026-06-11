#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    string ans = "";
    int diffx, diffy;
    // 1st one way
    diffx = abs(sx - gx);
    for (int i = 0; i < diffx; i++)
    {
        ans += 'R';
    }
    diffy = abs(sy - gy);
    for (int i = 0; i < diffy; i++)
    {
        ans += 'U';
    }
    // 1st return
    for (int i = 0; i < diffx; i++)
    {
        ans += 'L';
    }
    for (int i = 0; i < diffy; i++)
    {
        ans += 'D';
    }
    // 2nd one way
    ans += 'D';
    for (int i = 0; i < diffx + 1; i++)
    {
        ans += 'R';
    }
    for (int i = 0; i < diffy + 1; i++)
    {
        ans += 'U';
    }
    ans += 'L';
    // 2nd return
    ans += 'U';
    for (int i = 0; i < diffx + 1; i++)
    {
        ans += 'L';
    }
    for (int i = 0; i < diffy + 1; i++)
    {
        ans += 'D';
    }
    ans += 'R';
    cout << ans << endl;
    return (0);
}