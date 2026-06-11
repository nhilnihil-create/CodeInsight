#include<bits/stdc++.h>
using namespace std;

int n,t;

main()
{
    int ans=0,mx=0;
    int nwmin=1e9;
    bool use=false;
    scanf("%d %d",&n,&t);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a<=nwmin)
        {
            nwmin=a;
            use=false;
            continue;
        }
        int get=a-nwmin;
        if(get>mx)
        {
            mx=get;
            ans=1;
            use=true;
        }
        else if(get==mx&&!use)
        {
            use=true;
            ans++;
        }
    }
    printf("%d\n",ans);
}
