#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, x, sum = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x <= k - x)
        {
            sum += x;
        }
        else
        {
            sum += k - x;
        }
    }
    cout << sum*2 << endl;
}