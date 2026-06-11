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
string s[5000];
ll ans(ll a,ll b,ll c)
{
ll x=max({a,b,c});
    ll y=min({a,b,c});
    return x-y;
}
ll test(ll x,ll y)
{
    ll z=INT_MAX,a,b,c;
    for(int i=1; i<y; i++)
    {
        a=i*x;
        ll rem=y-i;
        if(rem==1)
        {
            ll mul=x/2;
            b=mul*rem;
            if(x%2)
                mul++;
            c=mul*rem;
            z=min(z,ans(a,b,c));
        }
        else
        {
            ll mul=x/2;
            b=mul*rem;
            if(x%2)
                mul++;
            c=mul*rem;
            z=min(z,ans(a,b,c));
            mul=rem/2;
            b=x*mul;
            if(rem%2)
                mul++;
            c=x*mul;
            z=min(z,ans(a,b,c));
        }
    }
    return z;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int a,b,c,x,y,z=INT_MAX;
    cin>>x>>y;
    cout<<min(test(x,y),test(y,x))<<endl;
    return 0;
}
