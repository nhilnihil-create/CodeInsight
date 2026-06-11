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
ll dg(ll a)
{
    int cnt=0;
    while(a>0)
    {
        a/=10;
        cnt++;
    }
    return cnt;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll n,ans=INT_MAX;
    cin>>n;
    for(int i=1; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            ll x=i;
            ll y=n/x;
            ans=min(ans,max(dg(x),dg(y)));
        }
    }
    cout<<ans<<endl;

    return 0;
}
