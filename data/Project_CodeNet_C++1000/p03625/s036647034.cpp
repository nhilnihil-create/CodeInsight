///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define u64 uint64_t
#define ll long long
#define endl "\n"
#define PI acos(-1)
#define pi pair<ll,ll>
#define fi first
#define si second
#define mkp make_pair
#define pb push_back
#define clr(arr) memset(arr,0,sizeof(arr))
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
deque<ll>dq;
map<ll,ll>mp;
set<ll>st;
vector<ll>vt;
ll mod=1e9+7;
const int N=1e6+5;
ll arr[N];

int main()
{
    IOS;
    ll n,m,x,y,z,i,j,k,p,f=0,tc,cnt=0,sum=0,mul=1,mi=1e18,ma=-1e18,a,b,c,d,sz;
    string str;
    char ch;
    double db;
    //code
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(i=0;i<n-1;i++)
    {
        if(i==0)
        {
            if(arr[i+1]==arr[i])
            {
                vt.pb(arr[i]);
            }
        }
        else
        {
            if(arr[i]==arr[i+1]||arr[i]==arr[i-1])
                vt.pb(arr[i]);
        }
    }
    if(arr[n-1]==arr[n-2]&&n>1)
    {
        vt.pb(arr[n-1]);
    }
    sz=vt.size();
    if(sz<4||n<4)
    {
        cout<<0<<endl;
        return 0;
    }
    if(vt[sz-1]==vt[sz-4])
    cout<<vt[sz-1]*vt[sz-1]<<endl;
    else
    {
        cout<<vt[sz-1]*vt[sz-4]<<endl;
    }



    //code
    return 0;
}
