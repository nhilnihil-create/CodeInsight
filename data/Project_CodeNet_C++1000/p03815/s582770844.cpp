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
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll x;
    cin>>x;
    if(x<=6)
    {
        cout<<"1"<<endl;

    }
    else if(x<=11)
    {
        cout<<"2"<<endl;
    }
    else
    {
        ll ans=x/11;
        ans*=2;
        ll rem=x%11;
        if(rem>=1 && rem<=6)
            ans++;
        else if(rem >6)
            ans+=2;

        cout<<ans<<endl;
    }
    return 0;
}
