#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;            //
 
int main(void)
{
    int W, a, b;
    cin >> W >> a >> b;
 
    int ans;
 
    // 緑の長方形が赤に触れているとき
    // b点
    if (a <= b && b <= a + W)
    {
        ans = 0;
    }
    // b + W 点
    else if (a <= b + W && b + W <= a + W)
    {
        ans = 0;
    }
    else if (a + W < b)
    {
        ans = abs(b - (a + W));
    }
    else if (b + W < a)
    {
        ans = abs(a - (b + W));
    }
    cout << ans << endl;
    return (0);
}