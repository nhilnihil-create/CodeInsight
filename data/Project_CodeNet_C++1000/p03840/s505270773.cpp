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
#define TC(c) printf("Case #%lld: ", ++c)
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
const ll N=300010, M=1000005;
ll n, x, a[N];
///I-0, J-3, L-4,
int main()
{
    for(int i=0;i<7;i++)
    in1(a[i]);
    ll s = (a[0]%2)+(a[3]%2)+(a[4]%2),f=0;
    if(s>=2) f=1;
    ll k=min(a[3], min(a[4], a[0]));
    if(k%2!=f) k--;
    k=max(0LL,k);
    ll res=(k*3);
    a[0]-=k, a[3]-=k, a[4]-=k;
    res+=((a[0]/2)*2)+a[1]+((a[3]/2)*2)+((a[4]/2)*2);
    printf("%lld\n",res);

    return 0;
}
/*

*/
