#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll d[305][305], cost[305][305];
int main()
{
    int n, i, j, k;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);


    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            d[i][j] = INT_MAX;

    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                d[i][j] = min(d[i][j], cost[i][k] + cost[k][j]);


      int flag = 1, road;
      ll sum = 0;
      for(i = 0; i < n; i++)
        for(j = i+1; j < n; j++)
            if(d[i][j] != cost[i][j]) flag = 0;

       if(flag)
       {
          for(i = 0; i < n; i++)
                for(j = i+1; j < n; j++)
                {
                    road = 1;
                    for(k = 0; k < n; k++)
                    {
                        if((d[i][j] == d[i][k] + d[k][j]) && (d[i][j] != d[i][k]) && (d[i][j] != d[k][j])) road = 0;
                    }
                    if(road) sum += d[i][j];
                }

            printf("%lld\n", sum);
       }
       else printf("-1\n");



    return 0;
}
