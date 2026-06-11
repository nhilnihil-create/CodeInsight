#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define getbit(n,i) (((n)&(1LL<<(i)))!=0)
#define setbit0(n,i) ((n)&(~(1LL<<(i))))
#define setbit1(n,i) ((n)|(1LL<<(i)))
#define lastone(n) ((n)&(-(n)))
#define read freopen("debug\\in.txt","r",stdin)
#define write freopen("debug\\out.txt","w",stdout)
#define DBG(a) cout<<#a<<" ->->->-> "<<a<<"\n"
#define EN cout<<"\n"
#define fi first
#define se second
#define PI (acos(-1))
#define fastread ios::sync_with_stdio(false);cin.tie(NULL)
#define mod (1000000007)
#define asz 200005
template<class T> ostream& operator<<(ostream &s,pair<T,ll> a)
{
    s<<a.fi<<' '<<a.se;
    return s;
}
int main()
{
    fastread;
    ll T=1;
//    cin>>T;
    for(ll qq=1;qq<=T; qq++)
    {
        vi v(7);
        for(auto &x:v)cin>>x;
        ll ans=v[1];
        if(v[0]%2&&v[3]%2&&v[4]>0||v[0]%2&&v[4]%2&&v[3]>0||v[4]%2&&v[3]%2&&v[0]>0)
        {
            ans+=3;
            v[0]--,v[3]--,v[4]--;
        }
        ans+=v[0]/2*2;
        ans+=v[3]/2*2;
        ans+=v[4]/2*2;
        cout<<ans<<endl;
    }
}

