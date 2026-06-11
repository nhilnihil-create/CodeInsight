#include <bits/stdc++.h>
#define LL long long
#define PII pair<int,int>
#define PIL pair<int,LL>
#define PLI pair<LL,int>
#define PIII pair<int,PII>
#define PLL pair<LL,LL>
#define PLII pair<LL,PII>
#define VI vector<int>
#define VVI vector<VI>
#define VL vector<LL>
#define VVL vector<VL>
#define VPII vector<PII>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define all(x) x.begin(),x.end()
#define watch(x) cout<<(#x)<<" = "<<(x)<<'\n'
#define mset(a,v) memset(a,v,sizeof(a))
#define setp(x) cout<<fixed<<setprecision(x)
#define EPS 0.00000000001
#define PI acos(-1)
#define loop(i,b,n) for(int i=b;i<n;++i)
#define rev_loop(i,b,n) for(int i=b;i>=n;--i)
using namespace std;

const int MOD = 1e9 + 7;
const LL MX = 1e9;
const LL INF = 1e9;

void print_a(VI v)
{
    if(v.size()) cout<<v[0];
    loop(i,1,v.size()) cout<<' '<<v[i];
    cout<<'\n';
}

VVI init_vvi(int n, int m, int val)
{
    return VVI(n,VI(m,val));
}

VVL init_vvl(int n, int m, LL val)
{
    return VVL(n,VL(m,val));
}

int main()
{
    //ofstream out("output.txt");
    //ifstream in("input.txt");
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,a;
    cin>>n;
    map<LL,int> mp;
    loop(i,0,n)
    {
        cin>>a;
        ++mp[a];
    }

    LL s1 = -1, s2 = -1;
    for(auto it = mp.crbegin(); it != mp.crend(); ++it)
    {
        if(s1 == -1)
        {
            if(it -> SS >= 4) {s1 = s2 = it->FF;}
            else if(it -> SS >= 2) {s1 = it->FF;}
        }
        else if(s2 == -1)
        {
            if(it -> SS >= 2) {s2 = it->FF;}
        }
    }

    LL ans;
    if(s1 == -1 || s2 == -1) ans = 0;
    else ans = s1 * s2;

    cout<<ans<<'\n';

    /*
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        loop(i,0,n) cin>>a[i];
    }
    */

    /*
    int n;
    cin>>n;
    int a[n];
    loop(i,0,n) cin>>a[i];
    */

    /*
    cout<<ans<<'\n';

    if(f) cout<<"YES\n";
    else cout<<"NO\n";

    if(f) cout<<"Yes\n";
    else cout<<"No\n";
    */

    return 0;
}
