#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    int x;
    scanf("%d", &x);
    int st = 1, dr = 45000, rez = -1;
    while(st <= dr)
    {
        int mij = (st + dr) / 2;
        int s = mij * (mij + 1) / 2;
        if(x <= s)
        {
            dr = mij - 1;
            rez = mij;
        }
        else st = mij + 1;
    }
    printf("%d", rez);
    return 0;
}
