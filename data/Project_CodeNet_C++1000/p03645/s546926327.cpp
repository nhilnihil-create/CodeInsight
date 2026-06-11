#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long m,n,i,j,x,y,z,a[300000],k=0,cnt=0,b[300000];
    cin>>n>>m;
    memset(a,0,sizeof(a));
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        a[x]=y;
        if(x==1)
        {
            b[k]=y;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        if(a[b[i]]==n)
        {
            cnt=1;
            break;
        }
    }
    if(cnt==1)
        cout<<"POSSIBLE"<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;


}
