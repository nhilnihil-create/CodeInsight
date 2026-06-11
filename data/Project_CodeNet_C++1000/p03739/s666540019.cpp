#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int arr[MAX],n;
int status(int a)
{
    if(a<0)
        return 1;
    else if(a>0)
        return 0;
    else
        return 2;
}
ll solve()
{
    ll cnt=0;
    ll sum=arr[0],f=0;
    if(arr[0]<0)
        f=1;
    else
        f=0;
    for(int i=1; i<n; i++)
    {
        f^=1;
        int add=arr[i];
        if(status(arr[i])!=f)
            add=0,cnt+=abs(arr[i]);
        sum+=add;
        if(status(sum)!=f)
        {
            cnt+=abs(sum)+1;
            if(f)
                sum=-1;
            else
                sum=1;
        }
    }
    return cnt;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    if(!arr[0])
    {
        arr[0]=1;
        ll x=solve()+1;
        arr[0]=-1;
        ll y=solve()+1;
        cout<<min(x,y)<<endl;
    }
    else
    {
        ll x,y;
        x=solve();
        if(arr[0]>0)
        {
            y=arr[0]+1;
            arr[0]=-1;
            y+=solve();
        }
        else
        {
            y=abs(arr[0])+1;
            arr[0]=1;
            y+=solve();
        }
        cout<<min(x,y)<<endl;
    }


    return 0;
}
