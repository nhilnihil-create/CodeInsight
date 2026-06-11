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
#define fi first
#define se second
#define PI (acos(-1))
#define fastread ios::sync_with_stdio(false);cin.tie(NULL)
#define mod (1000000007)
#define asz 500005
template<class T,class V> ostream& operator<<(ostream &s,pair<T,V> a)
{
    s<<a.fi<<' '<<a.se;
    return s;
}
int main()
{
    fastread;
    ll T=1;
//    cin>>T;
    for(ll qq=1;qq<=T;qq++)
    {
        ll n,a,b,c,d;
        cin>>n>>a>>b>>c>>d;
        if(a>b)swap(a,b);
        n--;
        b+=n*c;
        for(ll i=0;i<=n;i++){
            if(a-b>=0&&a-b<=n*(d-c))return cout<<"YES"<<endl,0;
            a+=d,b-=c;
        }
        cout<<"NO"<<endl;
    }
    return 0;
}