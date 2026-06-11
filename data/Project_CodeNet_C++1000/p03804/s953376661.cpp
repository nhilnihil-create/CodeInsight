#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define inf 500000000
#define IOS ios_base::sync_with_stdio(0)
#define meM(y,a) memset(y,a,sizeof y)
#define sC(a) scanf("%d",&a)
#define alL(a) a.begin(),a.end()
#define prinT(a,sz)  cout<<a[0];for(int i=1;i<sz;i++)cout<<" "<<a[i];cout<<endl
#define ranD srand(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int,int>pi;
typedef pair<ll,ll>pll;
//int fx[]={0,0,1,-1};
//int fy[]={1,-1,0,0};
//int gx[]={0,0,1,1,1,-1,-1,-1};
//int gy[]={1,-1,0,1,-1,0,1,-1};
bool check(int n,int p){return (1<<p)&n;}
char ara[100][100],b[100][100];
int n,m;
bool found(int x,int y)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(b[i][j]!=ara[i+x][j+y])return 0;
        }
    }
    return 1;
}
int main()
{
    IOS;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)cin>>ara[i][j];
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
        cin>>b[i][j];
    bool flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(found(i,j))
            {
                flag=1;
//                cout<<"found at "<<i<<" "<<j<<endl;
            }
        }
        if(flag)break;
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}






