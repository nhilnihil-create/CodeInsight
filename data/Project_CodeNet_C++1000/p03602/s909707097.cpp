#include<bits/stdc++.h>

using namespace std;

int in()
{
    int a;
    scanf("%d",&a);
    return a;
}

int main()
{
    int a[305][305];
    int n=in();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++){
            a[i][j]=in();
        }
    }
    long long ans=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            bool hoise=1;
            for(int k=0; k<n; k++)
            {
                if(a[i][j]==(a[i][k]+a[k][j])&&(a[i][j]!=a[i][k])&&(a[k][j]!=a[i][j]))
                    hoise=0;
                else if(a[i][j]>(a[i][k]+a[k][j])&&a[i][k]&&a[k][j])
                {
                    printf("-1\n");
                    return 0;
                }
            }
            if(hoise)
            {
                ans+=a[i][j];
            }
        }
    }
    printf("%lld\n",ans);
}
