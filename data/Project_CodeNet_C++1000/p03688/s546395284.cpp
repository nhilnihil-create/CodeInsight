#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int a[maxn];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    if(a[n] - a[1] >= 2)
    {
        cout << "No" << endl;
        return 0;
    }
    else if(a[n] - a[1] == 1)
    {
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] == a[1])
            {
                cnt++;
            }
        }
        // cout << cnt << a[n] << endl;
        if(n - cnt >= 2 * (a[n] - cnt) && a[n] - cnt > 0)
        {
            cout << "Yes" << endl;
            return 0;
        }
        else
        {
            cout << "No" << endl;
            return 0;
        }
    }
    else
    {
        if(a[1] == n - 1)
        {
            cout << "Yes" << endl;
            return 0;
        }
        if(a[1] * 2 <= n)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        
    }
    
}