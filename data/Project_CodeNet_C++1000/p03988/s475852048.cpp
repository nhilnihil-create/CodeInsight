#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
bool flag = true;
int n,tong[maxn],maxx,minn;

int main()
{
    scanf("%d",&n);
    minn = n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d",&x);
        tong[x]++;
        maxx = max(maxx,x);
    }
    if (tong[maxx] <= 1)
        flag = false;
    tong[maxx] -= 2;
    for (int i = 2; i <= maxx; i++)
    {
        int temp = max(i - 1,maxx - i + 1);
        minn = min(minn,temp + 1);
        if (!tong[temp])
            flag = false;
        tong[temp]--;
    }
    for (int i = 1; i < minn; i++)
        if (tong[i])
            flag = false;
    if (flag)
        puts("Possible");
    else
        puts("Impossible");

    return 0;
}
