#include <bits/stdc++.h>

using namespace std;

int n, x;

int main()
{
    cin >> n >> x;
    int l = 2 * n - 1;
    if(x == 1 || x == l)
    {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    if(n == 2)
    {
        cout << "1 2 3\n";
        return 0;
    }
    if(x == 2)
    {
        int val;
        val = 1;
        for(int i = 1; i <= n - 3;)
        {
            if(val != l && val != 1 && val != x && val != l - 1)
            {
                cout << val << "\n";
                i++;
            }
            val++;
        }
        cout << l << "\n" << 1 << "\n" << x << "\n" << l - 1 << "\n";
        val = 2 * n - 1;
        for(int i = 1; i <= n - 2;)
        {
            if(val != l && val != 1 && val != x && val != l - 1)
            {
                cout << val << "\n";
                i++;
            }
            val--;
        }
    }
    else
    {
        int val;
        val = 1;
        for(int i = 1; i <= n - 3;)
        {
            if(val != 1 && val != l && val != x && val != 2)
            {
                cout << val << "\n";
                i++;
            }
            val++;
        }
        cout << 1 << "\n" << l << "\n" << x << "\n" << 2 << "\n";
        val = 2 * n - 1;
        for(int i = 1; i <= n - 2;)
        {
            if(val != 1 && val != l && val != x && val != 2)
            {
                cout << val << "\n";
                i++;
            }
            val--;
        }
    }
    return 0;
}
