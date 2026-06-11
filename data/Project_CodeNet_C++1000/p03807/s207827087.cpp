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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
    for(ll qq=1;qq<=T; qq++)
    {
        ll n;
        cin>>n;
        ll od=0;
        while(n--){
            ll x;
            cin>>x;
            od+=x%2;
        }
        if(od%2==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
