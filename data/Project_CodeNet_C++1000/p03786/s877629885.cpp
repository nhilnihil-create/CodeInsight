#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define inf 1000000000
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
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
const int N=100010;
ll ara[N];
int main()
{
    IOS;
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>ara[i];
    sort(ara,ara+n);
    int ans=n,last=-1;
    ll sum=0;
//    prinT(ara,n);
    for(int i=0;i<n-1;i++)
    {
        sum+=ara[i];
        if(sum*2<ara[i+1])last=i;
    }
    cout<<ans-last-1<<endl;
}








