#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr[100010];

void f(int x, int p, int d, int dis[])
{
    dis[x] = d;
    for(int y : arr[x])
        if(y != p)
            f(y, x, d + 1, dis);
}

int dis1[100010];
int disn[100010];

int main()
{
    int i;
    scanf("%d", &n);
    for(i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    f(1, 1, 0, dis1);
    f(n, n, 0, disn);

    int cnt1 = 0, cntn = 0;

    for(i = 1; i <= n; i++)
    {
        if(dis1[i] <= disn[i])
            cnt1++;
        else
            cntn++;
    }

    if(cnt1 > cntn)
        puts("Fennec");
    else
        puts("Snuke");

    return 0;
}