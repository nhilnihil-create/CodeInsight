#include<bits/stdc++.h>
using namespace std;
#define inf 1000000008
int w[300][300],dist[300][300];
int main()
{
    int n,i,j,k;
    long long ans=0,sum=0;
    cin>>n;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>dist[i][j];
            sum+=dist[i][j];
            //dist[i][j]=w[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        dist[i][i]=inf;
    }
    for (k = 0; k < n; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < n; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = i+1; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] == dist[i][j])
                {
                    if(!w[i][j])
                    {
                        //cout<<dist[i][j]<<endl;
                        ans+=dist[i][j];
                        w[i][j]=1;
                    }
                }
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }
    cout<<(sum/2)-ans<<endl;
}
