#include <iostream>

using namespace std;
int a[505][505];
int n,m,h,w,i,j;
int main()
{
    cin>>n>>m>>h>>w;
    if(n%h==0&&m%w==0)
    {
        cout<<"No";
        return 0;
    }
    if(n%h!=0)
    {
        for(i=1;i<=n;i+=h)
            for(j=1;j<=m;j++)
              a[i][j]=(h-1)*1000-1;
    }
    else
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j+=w)
              a[i][j]=(w-1)*1000-1;
    }
     for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(!a[i][j])
                a[i][j]=-1000;
    cout<<"Yes\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
