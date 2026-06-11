#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int n,k;
    cin >> n;
    vector<int> a(7);
    a[0] = 2;
    for (int i = 1;i < 7;i++)
    {
        a[i] = 2 * a[i - 1]; 
    }

    int ans;
    if (n < 2) ans = 1;
    for (int i = 0;i < 7;i++)
    {
        if (n >= a[i]) ans = a[i];
    }

    cout << ans << endl;
    
    
    return 0;
}
