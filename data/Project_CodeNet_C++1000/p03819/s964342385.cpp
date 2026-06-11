#include <bits/stdc++.h>
#define N 300002
using namespace std;
vector <int> vec[N];
int dd[N],bit[N],sl[N],k,x,i,kq[N],n,m,l,r,cnt,ma[N];
void update(int i,int k)
{
    dd[i]+=k;
    while(i<=m) { bit[i]+=k; i+=(i & -i); }
}
int get(int l,int r)
{
    int i=r,kq=0;
    while(i>=l)
        if(i-(i & -i)>=l) { kq+=bit[i]; i-=(i & -i); }
        else { kq+=dd[i]; i--; }
    return kq;
}
int main()
{
    //freopen("ntu.inp","r",stdin);
    //freopen("ntu.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>l>>r;
        vec[r].push_back(l); sl[l]++;
    }
    for(x=1;x<=m;x++)
    {
        cnt+=sl[x];
        update(x,sl[x]);
        for(k=1;k*k<=x;k++)
            if(x%k==0)
            {
                kq[k]+=cnt-get(1,ma[k]);
                ma[k]=x;
                if(k!=x/k)
                {
                    kq[x/k]+=cnt-get(1,ma[x/k]);
                    ma[x/k]=x;
                }
            }
        cnt-=vec[x].size();
        for(i=0;i<vec[x].size();i++)
        {
            k=vec[x][i];
            update(k,-1);
        }
    }
    for(i=1;i<=m;i++) cout<<kq[i]<<'\n';
}
