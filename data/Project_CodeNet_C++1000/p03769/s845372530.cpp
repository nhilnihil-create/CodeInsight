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
    for(ll qq=1;qq<=T; qq++)
    {
        ll n;
        cin>>n;
        vi ans;
        ll x=log2(n);
        ll ind=1;
        for(int i=0;i<x;i++)ans.push_back(ind++);
        for(int i=0;i<x;i++)ans.push_back(ans[i]);
        for(ll i=x-1;i>=0;i--)
        {
            if(getbit(n,i))
            {
                ans.insert(ans.begin(),ind++);
                ans.insert(ans.end()-i,ind-1);
            }
        }
        ans.push_back(ind++);
        ans.push_back(ind-1);
        cout<<ans.size()<<endl;
        for(auto x:ans)cout<<x<<' ';
        cout<<endl;
    }
}

