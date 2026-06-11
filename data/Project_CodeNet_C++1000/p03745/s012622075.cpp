#include <bits/stdc++.h>
using namespace std;

int i;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int count = 0;

    for (i = 0; i < n; i++)
    {
        while (i + 1 < n && a[i] == a[i + 1])
        {
            i++;
        }
        if (i + 1 < n && a[i] < a[i + 1])
        {
            while (a[i] <= a[i + 1])
            {
                i++;
            }
        }
        else if (i + 1 < n && a[i] > a[i + 1])
        {
            while (a[i] >= a[i + 1])
            {
                i++;
            }
        }
        count++;
    }

    cout << count;
}