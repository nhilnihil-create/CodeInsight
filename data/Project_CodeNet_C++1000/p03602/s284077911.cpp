#include<bits/stdc++.h>
#define i64 long long
#define inf 1000000000000000000
using namespace std;
const int MAXN=319;

i64 ara[MAXN][MAXN];
bool dist[MAXN][MAXN];




int main()
{
    i64 n,x,u,v,w;
    scanf("%lld",&n);



    i64 sum=0;
    for(i64 i=1; i<=n; i++)
    {
        for(i64 j=1; j<=n; j++)
        {
            scanf("%lld",&x);
            ara[i][j]=x;

            if(j>i)
                sum+=x;
        }
    }

  //  cout<<sum<<endl;

    for(i64 k=1; k<=n; k++)
        for(i64 i=1; i<=n; i++)
            for(i64 j=1; j<=n; j++)
            {
                if(ara[i][k]+ara[k][j]<ara[i][j] || ara[i][k]+ara[k][j]<ara[j][i])
                {
                    printf("-1\n");
                    return 0;
                }
            }


    for(i64 k=1; k<=n; k++)
        for(i64 i=1; i<=n; i++)
            for(i64 j=i+1; j<=n; j++)
            {


                if(k==i || k==j) continue;
                if(ara[i][k]+ara[k][j]==ara[i][j])
                {
                    dist[i][j]=true;

                }
            }


     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=n;j++)
         {
             if(dist[i][j]==true)
                sum-=ara[i][j];
         }
     }



    cout<<sum<<endl;

}
