
#include <bits/stdc++.h>

using namespace std;
//-----pre_def----
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
#define pi 3.1415926
#define eps 0.000001
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define rif(i, a, b) for (int i = a; i >= b; i--)
#define init_h memset(h, -1, sizeof h), idx = 0;
//---------------
double rx, ry, r, x, y;

double get_dis(double x1, double y1, double x2, double y2)
{
    double c = (x1 - x2) * (x1 - x2);
    double d = (y1 - y2) * (y1 - y2);
    return sqrt(c + d);
}

double get_rad2()
{
    double t1 = (x - rx) / (y - ry);
    double t2 = atan(t1);
    return 180 * t2 / pi;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int StartTime = clock();
#endif

    LL n, m;
    cin >> n >> m;
    LL t = __gcd(n, m);
    LL u = n / t;
    LL v = 3 * (u - 1);
    cout << t * v << endl;

#ifndef ONLINE_JUDGE
    printf("Run_Time = %d ms\n", clock() - StartTime);
#endif
    return 0;
}
