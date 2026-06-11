#include<bits/stdc++.h>
using namespace std;

int arr[100100];

main()
{
    int ans=0;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]==i)
        {
            if(i!=1&&arr[i-1]==i-1)
            {
                arr[i]=-1;
            }
            else
            {
                ans++;
            }
        }
    }
    printf("%d\n",ans);
}
