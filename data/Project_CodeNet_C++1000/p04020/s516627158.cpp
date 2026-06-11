///in the name of Allah the most beneficent the most merciful.
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 1e18
#define MIN -1e18
#define MOD 998244353
//#define mod2 20071027
//#define MOD 998244353
#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a) for(int i=1;i<=a;i++)
#define base 139
//#define mod 1000074259
#define base2 31
#define memz(a) memset(a, 0, sizeof(a))
#define memn(a) memset(a, -1, sizeof(a))
#define in1(a) scanf("%lld", &a)
#define in2(a, b) scanf("%lld%lld", &a, &b)
#define TC(c) printf("Case %lld: ", ++c)
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
const ll N=300010, M=1000005;
ll n,k, a[N], res;
int main()
{
    in1(n);
    for(int i=0;i<n;i++)
    {
        in1(a[i]);
        if(i>0)
        {
            ll t = min(a[i], a[i-1]);
            res+=t;
            a[i]-=t;
        }
        if((a[i]/2)>0)
        {
            ll t = a[i]/2;
            res+=t;
            a[i]-=(2*t);
        }
    }
    printf("%lld\n",res);
    return 0;
}
/*

*/
