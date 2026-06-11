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
template<class T> ostream& operator<<(ostream &s,pair<T,ll> a)
{
    s<<a.fi<<' '<<a.se;
    return s;
}
ll check(vi &v,bool p=false)
{
    if(!p)shuffle(v.begin(),v.end(),rng);
    vi temp=v;
    while(temp.size()>1)
    {
        if(p)
        {
//            for(auto x:temp)cout<<x<<' ';
//            cout<<endl;
        }
        vi t;
        for(int i=1;i+1<temp.size();i++)
        {
            vi r;
            r.push_back(temp[i]);
            r.push_back(temp[i+1]);
            r.push_back(temp[i-1]);
            sort(r.begin(),r.end());
            t.push_back(r[1]);
        }
        temp=t;
    }
    return temp[0];
}
int main()
{
    fastread;
    ll T=1;
//    cin>>T;
    for(ll qq=1;qq<=T; qq++)
    {
        ll n,x;
        cin>>n>>x;
        if(x==2*n-1||x==1)
        {
            cout<<"No"<<endl;
            return 0;
        }
        vi ans(2*n-1);
        ans[n-1]=x;
        ans[n-2]=x-1;
        ans[n]=x+1;
        vi taken(2*n);
        taken[x]=taken[x+1]=taken[x-1]=1;
        if(n!=2)
        {
            if(x!=2)ans[n+1]=x-2,taken[x-2]=1;
            if(x!=2*n-2)ans[n-3]=x+2,taken[x+2]=1;
            ll l=1;
            for(auto &x:ans)
            {
                while(l<2*n&&taken[l]==1)l++;
                if(x==0)x=l,taken[l]=1;
            }
        }
//        assert(check(ans,1)==x);
        cout<<"Yes"<<endl;
        for(auto x:ans)cout<<x<<' ';
        cout<<endl;
    }

}