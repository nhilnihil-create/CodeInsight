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
ll fact[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int a,b;
    cin>>a>>b;
    fact[0]=1;
    for(ll i=1; i<MAX; i++)
        fact[i]=(fact[i-1]*i)%MOD;
    if(abs(a-b)>1)
        cout<<"0"<<endl;
    else
    {
        ll ans=(fact[a]*fact[b])%MOD;
        if(a==b)
            ans=(ans*2ll)%MOD;
        cout<<ans<<endl;
    }


    return 0;
}
