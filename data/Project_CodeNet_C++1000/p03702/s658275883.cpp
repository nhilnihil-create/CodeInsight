#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
using namespace std;
typedef long long ll;
#define mit map<int,int>::iterator
#define sit set<int>::iterator
#define itrm(g,x) for(mit g=x.begin();g!=x.end();g++)
#define itrs(g,x) for(sit g=x.begin();g!=x.end();g++) 
#define ltype int
#define rep(i,j,k) for(ltype (i)=(j);(i)<=(k);(i)++)
#define pii pair<int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
const int inf=0x3f3f3f3f,
mod=1000000007;
const double pi=3.1415926535897932,
eps=1e-6;
int n,h[100005],g;ll a,b;
bool check(ll k)
{
    ll cnt=0;
    rep(i,1,n)
    cnt+=max((h[i]-k*b+a-b-1)/(a-b),0ll);
    return cnt<=k;
}
int main()
{
    scanf("%d%lld%lld",&n,&a,&b);
    rep(i,1,n) scanf("%d",h+i),g=max(g,h[i]);
    ll l=1,r=g;
    while(l<r){
        ll mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}