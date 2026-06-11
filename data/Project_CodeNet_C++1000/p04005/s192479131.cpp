#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}
double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    vector<ll>a(3);
    cin>>a[0]>>a[1]>>a[2];
    sort(a.begin(), a.end());
    if(a[0]%2==0||a[1]%2==0||a[2]%2==0){
        cout << 0 << endl;
    }
    else{
        cout << a[0] * a[1] << endl;
    }
    return 0;
}