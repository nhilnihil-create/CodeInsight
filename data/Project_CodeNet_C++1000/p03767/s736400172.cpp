#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const long long MOD = 1e9+7;


#define INPUT(x)                freopen(x,"r",stdin)
#define OUTPUT(x)               freopen (x,"w",stdout)


#define pb                      push_back
#define endl                    '\n'
#define LCM(a,b)                (a/__gcd(a,b))*b
#define GCD(a,b)                __gcd(a,b)
#define SP(x,y)                 fixed<<setprecision((y))<<(x)
#define PI                      acos(-1.0)
#define distance(x1,y1,x2,y2)   sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define MAX                     1e9 + 9

#define taratari                ios_base::sync_with_stdio(0);cin.tie(NULL);


int main()
{
    taratari

    ll n;
    cin>>n;

    ll a[n*3];

    for(ll i=0;i<3*n;i++)
    {
        cin>>a[i];
    }

    sort(a,a+3*n);

    ll sum=0;

    for(int i=n;i<3*n;i=i+2)
    {
        sum+=a[i];
    }


    cout<<sum;




    return 0;

}

