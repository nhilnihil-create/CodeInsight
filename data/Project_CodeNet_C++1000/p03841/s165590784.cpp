#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
const int nmax=505;
pair<int,int> v[nmax];
vector<int> ad[nmax];
int a[nmax*nmax],ans[nmax*nmax],fr[nmax*nmax];
int ini[nmax];
int p,u,n,i,j,curr,nr;
int main()
{
    //freopen("data.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>v[i].first;
        v[i].second=i;
        ini[i]=v[i].first;
    }
    sort(v+1,v+n+1);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<v[i].second;j++)
            a[++u]=v[i].second;
    }
    curr=1;
    for(i=1;i<=n*n;i++)
    {
        if(v[curr].first==i)
        {
            for(j=1;j<=n-v[curr].second;j++)
                fr[++nr]=v[curr].second;
            ans[i]=v[curr].second;
            curr++;
        }
        else
        {
            if(p<u)
            {
                ans[i]=a[++p];
            }
            else
            {
                if(nr) ans[i]=fr[nr--];
            }
        }
        ad[ans[i]].push_back(i);
    }
    for(i=1;i<=n;i++)
        if(ad[i].size()<n||ad[i][i-1]!=ini[i])
    {
        cout<<"No";
        return 0;
    }
    cout<<"Yes\n";
    for(i=1;i<=n*n;i++)
        cout<<ans[i]<<' ';
    return 0;
}
