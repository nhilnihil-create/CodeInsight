#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    bool swap = false;
    
    while (true)
    {
        int nEven = 0, nOdd = 0;
        int theOdd = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 1)
            {
                nOdd++;
                theOdd = a[i];
            }
            else
                nEven++;
        }
        
        if (n % 2 != nOdd % 2)
        {
            // first wins, no need to do shit
            
            cout << (!swap ? "First" : "Second") << '\n';
            return 0;
        }
        else
        {
            // try swap
            if (nOdd == 1 && theOdd != 1)
            {
                int g = 0;
                for (int i = 0; i < n; i++)
                {
                    if (a[i] % 2 == 1)
                    {
                        a[i]--;
                    }
                    g = __gcd(g, a[i]);
                }
                
                for (int i = 0; i < n; i++)
                    a[i] /= g;
                
                swap = !swap;
            }
            else
            {
                cout << (!swap ? "Second" : "First") << '\n';
                return 0;
            }
        }
    }
    
    return 0;
}