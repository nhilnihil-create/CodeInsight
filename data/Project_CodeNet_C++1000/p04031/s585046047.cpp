#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[105],cost=4000005;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);

    for(int i=-100; i<=100; i++)
    {
        int sum=0;
        for(int j=0; j<n; j++)
        {
            int t = (i-a[j])*(i-a[j]);
            sum+=t;

        }

        if(sum<cost)
            cost=sum;
    }
    printf("%d\n",cost);

    return 0;
}
