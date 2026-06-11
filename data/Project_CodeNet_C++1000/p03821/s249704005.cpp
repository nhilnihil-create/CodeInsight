#include<bits/stdc++.h>
using namespace std;
long long int n,a,r,r1,sm,st,ar[100005],br[100005];

int main()
{
    cin>>n;
    for(a=0;a<n;a++)
    {
        cin>>ar[a]>>br[a];
    }
    sm=0;
    for(a=n-1;a>=0;a--)
    {
        r=(sm+ar[a])%br[a];
        if(r!=0)
        {
            r1=(sm+ar[a])/br[a];
            st=((r1+1)*br[a])-(sm+ar[a]);
            sm=sm+st;
            
        }
    }
    cout<<sm<<endl;
    return 0;
}
