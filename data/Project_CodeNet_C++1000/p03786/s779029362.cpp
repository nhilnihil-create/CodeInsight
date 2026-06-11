#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<int> a(n);
    vector<long long> suma(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        suma[i + 1] = suma[i] + a[i];
    }

    long long ans = 0;
    for (int i = 1; i < n; i++)
    {
        if(2 * suma[i] < a[i])ans = i;
    }
    
    cout << n - ans << endl;
}