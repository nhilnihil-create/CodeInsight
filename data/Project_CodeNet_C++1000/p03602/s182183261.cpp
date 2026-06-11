
/*Hey, What's up?*/

#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<long long>v;
long long x[400][400],y[400][400];
int main()
{
    fastio;
    long long a=0,b=0,c,d,e,f=0,l,g,m,n,k,i,j,t,p,q;
    cin>>n;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>x[i][j];
            y[i][j]=x[i][j];
        }
    }
    g=1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j)
                continue;
            for(p=0; p<n; p++)
            {
                if(i==p||j==p)
                    continue;
                if(x[i][p]+x[p][j]<x[i][j])
                {
                    g=0;
                }
                else if(x[i][p]+x[p][j]==x[i][j])
                {
                    y[i][j]=0;
                }
            }
        }
    }
    if(!g)
    {
        cout<<-1<<'\n';
        return 0;
    }
    f=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            f+=y[i][j];
        }
    }
    f/=2;
    cout<<f<<'\n';
    return 0;
}
