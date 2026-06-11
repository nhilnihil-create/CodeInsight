#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;
long long n, a, b, x[100003];
long long ans;
int main()
{
    cin >> n >> a >> b;
    for(int i = 1;i <= n;++ i)
    {
        cin >> x[i];
    }
    for(int i = 1;i < n;++ i)
    {
        if((x[i + 1] - x[i]) * a < b) ans = ans + (x[i + 1] - x[i]) * a;
        else ans = ans + b;
    }
    cout << ans << endl;
    return 0;
}