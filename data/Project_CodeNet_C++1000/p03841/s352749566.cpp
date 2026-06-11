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
        vii v(n);
        for(int i=0;i<n;i++){
            cin>>v[i].fi;
            v[i].fi--;
            v[i].se=i+1;
        }
        sort(v.begin(),v.end());
        vi ans;
        vi done;
        ll l1=0,l2=0,d=0;
        while(ans.size()<n*n){
            while(l1<n&&v[l1].se==d+1)l1++,d=0;
            if(l2<n&&ans.size()==v[l2].fi){
                if(l1<=l2)break;
                ans.push_back(v[l2].se);
                for(int i=v[l2].se;i<n;i++)done.push_back(v[l2].se);
                l2++;
                continue;
            }
            if(l1<n)ans.push_back(v[l1].se),d++;
            else if(done.empty())break;
            else ans.push_back(done.back()),done.pop_back();
        }
        if(ans.size()==n*n){
            cout<<"Yes"<<endl;
            for(int i=0;i<n*n;i++)cout<<ans[i]<<(i==n*n-1?'\n':' ');
        }
        else cout<<"No"<<endl;
    }
}