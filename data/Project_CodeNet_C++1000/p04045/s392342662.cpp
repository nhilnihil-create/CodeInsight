#include<bits/stdc++.h>
using namespace std;
int ara[11];
int r(int n)
{
    while(n)
    {
        int p=n%10;
       
        n/=10;
        if(ara[p]==1)
            return 0;
    }

    return 1;
}
int main()
{
    int n,k,x,i,p;
    cin>>n>>k;
    for(i=0;i<k;i++)
    {
        cin>>x; ara[x]=1;
    }
    for(i=n;;i++)
    {
        p=r(i);
        if(p==1)
        {
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}
