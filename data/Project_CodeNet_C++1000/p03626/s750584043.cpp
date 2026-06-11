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
string x,y;
int len;
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>len;
    cin>>x;
    cin>>y;
    ll ans=1,last=0;
    if(x[0]==y[0])
        ans=3,last=1;
    else
        ans=6,last=2;
    for(int i=last; i<len; i++)
    {
        if(x[i]==y[i])
        {
            if(last==1)
                ans*=2;
            last=1;
        }
        else{
            if(last==1)
                ans*=2;
            else
                ans*=3;
            last=2;
            i++;
        }
        ans%=MOD;
    }
    cout<<ans<<endl;




    return 0;
}
