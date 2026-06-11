#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ,di = 0;
    scanf("%d",&n);
    vector <int> cnt(n);
    for(int a,i=0; i<n; i++)
        scanf("%d",&a) ,cnt[a]++ ,di = max(di ,a);

    cnt[(di+1)/2] -=(di&1 ? 2 : 1);
    bool poss = !cnt[(di+1)/2];
    for(int i=(di+1)/2+1; i<=di; i++)
        poss &= (cnt[i] >= 2);
    for(int i=1; i<=(di+1)/2; i++)
        poss &= !cnt[i];

    printf(poss? "Possible\n" : "Impossible\n");
}
