#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int N;
    cin >> N;
    vector<bool> color(9, false);
    int red = 0;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        if (a[i] <= 399)
        {
            color[0] = true;
        }
        else if (a[i] >= 400 && a[i] <= 799)
        {
            color[1] = true;
        }
        else if (a[i] >= 800 && a[i] <= 1199)
        {
            color[2] = true;
        }
        else if (a[i] >= 1200 && a[i] <= 1599)
        {
            color[3] = true;
        }
        else if (a[i] >= 1600 && a[i] <= 1999)
        {
            color[4] = true;
        }
        else if (a[i] >= 2000 && a[i] <= 2399)
        {
            color[5] = true;
        }
        else if (a[i] >= 2400 && a[i] <= 2799)
        {
            color[6] = true;
        }
        else if (a[i] >= 2800 && a[i] <= 3199)
        {
            color[7] = true;
        }
        else
        {
            color[8] = true;
            red++;
        }
    }

    int basic = 0;
    for (int i = 0; i < 8; i++)
    {
        if (color[i] == true)
        {
            basic++;
        }
    }

    int mn = basic;
    if (basic == 0 && red > 0)
    {
        mn = 1;
    }
    int mx = basic + red;
    cout << mn << " " << mx << "\n";
    return (0);
}