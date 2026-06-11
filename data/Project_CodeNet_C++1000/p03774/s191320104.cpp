#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n,m,x,ans=1000000000,p;
    cin >> n >> m;
    int a[n], b[n], c[m], d[m];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> c[i] >> d[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            x = abs(a[i]-c[j])+abs(b[i]-d[j]);
            if(ans>x){
                ans = x;
                p = j+1;
            }
        }
        cout << p << endl;
        ans = 1000000000;
    }
    return 0;
}