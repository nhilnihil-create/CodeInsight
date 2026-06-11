#include <bits/stdc++.h>

using namespace std;

int arr[100010];
int mxs[100010];

int main()
{
    int n, t, i;
    scanf("%d%d", &n, &t);
    for(i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    for(i = n; i >= 1; i--)
        mxs[i] = max(mxs[i + 1], arr[i]);

    int mx = 0, cnt = 0;
    for(i = 1; i <= n; i++)
    {
        int d = mxs[i + 1] - arr[i];
        if(d > mx)
        {
            mx = d;
            cnt = 1;
        }
        else if(d == mx)
            cnt++;
    }

    printf("%d\n", cnt);
    return 0;
}