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
        ll n;
        cin>>n;
        vi ara(n);
        vii a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i].fi;
            ara[i]=a[i].fi;
            a[i].se=i;
        }
        sort(a.begin(),a.end());
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            if(abs(a[i].se-i)%2)
            {
                while(1){
                    ll x=lower_bound(a.begin(),a.end(),ii(ara[i],0))-a.begin();
                    a[x].se=i;
                    if(abs(i-x)%2==0)
                    {
                        a[x].se=x;
                        swap(ara[i],ara[x]);
                    }
                    else break;
                }
                ll x=lower_bound(a.begin(),a.end(),ii(ara[i],0))-a.begin();
                a[x].se=a[i].se;
                swap(ara[i],ara[a[i].se]);
                a[i].se=i;
                ans++;
            }
            else
            {
                ll x=lower_bound(a.begin(),a.end(),ii(ara[i],0))-a.begin();
                a[x].se=a[i].se;
                swap(ara[i],ara[a[i].se]);
                a[i].se=i;
            }
        }
        cout<<ans<<endl;
    }
}