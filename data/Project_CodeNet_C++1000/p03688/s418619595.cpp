#include<bits/stdc++.h>
using namespace std;
#define M 100005

int ara[M];

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) scanf("%d", ara+i);

    sort(ara+1, ara+n+1);

    bool ans;

    if(ara[1] == ara[n]) ans = (ara[1] == n-1 || 2*ara[1] <= n);
    else if(ara[1]+1 == ara[n])
    {
        int x = 0, y = 0;

        for(int i = 1; i <= n; i++)
        {
            if(ara[i] == ara[1]) x++;
            else y++;
        }

        int p = n-x;
        int q = ara[n]-x;

        if(q <= 0) ans = false;
        else ans = (2*q <= p);
    }
    else ans = false;

    printf("%s\n", ans? "Yes": "No");

    return 0;
}
