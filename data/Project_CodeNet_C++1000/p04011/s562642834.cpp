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
    cin>>n>>k>>x>>y;
    k=min(n,k);
    sum+=x*k;
    k=n-k;
    if(n>k)
        sum+=y*k;
    cout<<sum<<endl;




    //code
    return 0;
}
