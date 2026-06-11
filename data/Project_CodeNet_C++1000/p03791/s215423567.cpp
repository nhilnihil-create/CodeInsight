#include <bits/stdc++.h>

using namespace std;

typedef long long li;
const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    
    vector<int> a;
    
    int lastx = -1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x = min(x, lastx + 2);
        lastx = x;
        
        a.push_back(x);
    }
    int bitch = 1;
    
    vector<int> free;
    for (int i = 0; i < n; i++)
        if (i + 1 < n && a[i] + 1 == a[i + 1])
            free.push_back(i + 2);
        
    for (int i = 0; i < n; i++)
    {
        int x = (2 * i < (int)free.size() ? free[2 * i] : n) - i;
        bitch = bitch * (li)x % MOD;
    }
    
    cout << bitch << endl;
    
    return 0;
}