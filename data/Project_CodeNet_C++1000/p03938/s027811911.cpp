#include<bits/stdc++.h>
#define FRU freopen("out.txt","w",stdout)
#define FRO freopen("in.txt","r",stdin)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mem(ara,n) memset(ara,n,sizeof ara)
#define loop(i,j,n) for(i=j;i<n;i++)
#define rloop(i,j,n) for(i=n;i>=j;i--)
#define INF 2147483647
#define ll long long
#define pii pair<int,int>
#define eps 1e-9
#define mii map<int,int>
#define vi vector<int>
#define all(n) n.begin(),n.end()
#define inf INF
#define INFLL 9223372036854775807
using namespace std;
int main()
{
    int n,m,cnt=0,i,j,k,tc,t;
    int a[100005],b[100005],p[100005],c[100005]={0};
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>p[i];
        a[i]=i;
        b[i]=n-i+1;
        //cout<<a[i]<<endl;
    }
    int x,y;
    int last=a[p[1]]+b[p[1]];
    for(i=2;i<=n;i++)
    {
        x=a[p[i]]+b[p[i]];
        if(last>=x)
        {
            y=last-x+1;//cout<<last<<" "<<x<<" "<<p[i]<<endl;
            for(j=p[i];j<=n;j++)a[j]+=y;
            for(j=p[i];j>0;j--)b[j]+=y;

        }
        last=a[p[i]]+b[p[i]];
    }
    for(i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
    for(i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl;
    //for(i=1;i<=n;i++)cout<<a[p[i]]+b[p[i]]<<" ";

}
