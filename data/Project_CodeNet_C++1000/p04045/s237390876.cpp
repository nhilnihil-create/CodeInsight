#include <bits/stdc++.h>

using namespace std;

int dig[10];

int main()
{
    int n, k; cin >> n >> k;
    for(int i = 0; i < k; i++)
    {
        int x; cin >> x;
        dig[x] = 1;
    }
    for(int i = n; i <= 1000000; i++)
    {
        int x = i;
        bool ok = true;
        while(x)
        {
            int d = x%10;
            if(dig[d])
                ok = false;
            x /= 10;
        }
        if(ok)
            return !(cout << i << endl);
    }
}

