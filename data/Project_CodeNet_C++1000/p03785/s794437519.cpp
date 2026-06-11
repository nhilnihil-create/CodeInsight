#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, c, k;
    cin >> n >> c >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int i = 0, bus = 0;
    while (i < n)
    {
        int ptr = i + 1;
        while (ptr < (i + c) && ptr < n)
        {
            if (a[ptr] > (a[i] + k))
                break;
            ptr++;
        }
        bus++;
        i = ptr;
    }
    cout << bus << endl;
    return 0;
}