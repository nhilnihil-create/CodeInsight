#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define ppb pop_back()
#define ppf pop_front()
#define all(vec) vec.begin(), vec.end()
#define fol(i,a,b) for(int i=a;i<b;i++)
#define loop(i,a,b) for(int i=a;i>=b;i--)
#define forr(x,arr) for(auto& x:arr)
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-7
#define sz(x) ((lli)(x).size())

using   lli     =   long long;
using   lld     =   long double;
using   ulli    =   unsigned long long int;
using   pll     =   pair<lli, lli>;
using   ttt     =   pair<lli, pll>;
using   vttt    =   vector<ttt>;
using   vll     =   vector<pll>;
using   vl      =   vector<lli>;
using   vi      =   vector<int>;
using   vvi     =   vector<vector<int>>;
using   cd      =   complex<lld>;
const double PI = acos(-1);

#ifndef tejasp
#define trace(...) {}
#define cotra(...) {}
#define end_routine() {}
#define localsys 0
#define endl '\n'
#endif

int tejas_919(int kkkk)
{
    lli n, m, k, q, u, v, temp=0, ans=0;
    cin>>n;
    int phase=1;
    lli pref[n+5]={}, sum[n+5]={};
    vi pos;
    char ch='+';
    fol(i,1,n+1)
    {
        if(i>1)
        {
            cin>>ch;
            if(ch=='-') pos.pb(i);
        }
        cin>>pref[i];
        if(ch=='+') ans+=pref[i];
        else ans-=pref[i];
        sum[i]=ans;
        pref[i]+=pref[i-1];
    }
    cotra(pos)
    trace(pref,n+1)
    fol(i,0,sz(pos)-1)
    {
        lli curans=0;
        int cur=pos[i]-1, next=pos[i+1]-1;
        trace(cur,next)
        curans = sum[cur]-(pref[next]-pref[cur])+(pref[n]-pref[next]);
        ans=max(ans,curans);
    }
    
    cout<<ans<<endl;
    return 0;
}

signed main()
{
    #ifdef tejasp
            freopen("input.txt", "rt", stdin);
            freopen("output.txt", "wt", stdout);
    #endif
    if(!localsys) { ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); }
    cout << fixed << setprecision(10);
    int t=1;
    //cin>>t;
    fol(i,0,t) { tejas_919(i+1); }
    end_routine();
    if(localsys) system("pause");
}
