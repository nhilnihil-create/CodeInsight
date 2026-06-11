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
        if (a[i] % 2 == 1)
        {
            count++;
        }
    }

    if (count % 2 == 1)
    {
        puts("NO");
    }
    else
    {
        puts("YES");
    }
}