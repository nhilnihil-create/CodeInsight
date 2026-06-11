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
        vi a(n);
        for(auto &x:a)cin>>x;
        sort(a.begin(),a.end());
        ll mx=a.back();
        ll l=mx;
        bool ok=true;
        a.pop_back();
        while(!a.empty()&&ok){
            ll u=1;
            while(!a.empty()&&a.back()==l)u++,a.pop_back();
            if(u==1)ok=false;
            else if(u>2&&mx%2&&l==(mx+1)/2)ok=false;
            if(!a.empty()){
                u=a.back();
                a.pop_back();
                if(u!=l-1)ok=false;
                if(mx%2==0&&u==mx/2&&!a.empty())ok=false;
                if(u<(mx+1)/2)ok=false;
                if(a.empty()&&(mx%2||u!=mx/2))ok=false;
                l=u;
            }
            else{
                if(mx%2==0||(mx+1)/2!=l)ok=false;
            }
        }
        if(ok)cout<<"Possible"<<endl;
        else cout<<"Impossible"<<endl;
    }
}