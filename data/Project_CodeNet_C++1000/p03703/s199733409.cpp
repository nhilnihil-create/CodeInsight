#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll, ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ppi pair<pii,int>
#define pip pair<int,pii>
#define pdd pair<double, double>
#define f first
#define s second
#define MOD 1000000007
#define mkp make_pair
#define M_PI 3.14159265358979323846
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define LOR(i,l,r) for (ll i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define LORD(i,r,l) for (ll i=r;i>=l;i--)
#define INF 1000000000
#define CL(x) memset(x,0,sizeof(x))
#define DEB(x) cout << #x << " : " << x << '\n'
#define ALL(x) x.begin(), x.end()
#define SZ(x) x.size()
#define UI(x) (int)(x-'A')
#define LI(x) (int)(x-'a')
typedef long long ll;

#define MXN 200005
int N;
ll K;
ll A[MXN];
ll psum[MXN];
vector<ll> vals;

struct segtree
{
    segtree(){}
    void init(int N)
    {
        this->N=N;
        build(1,N,1);
    }
    void build(int l, int r, int id=1)
    {
        if(l==r)st[id]=0;
        else
        {
            int mid = (l+r)/2;
            build(l,mid,id<<1);
            build(mid+1,r,(id<<1)|1);
            up(id);
        }
    }
    void up(int id)
    {
        st[id]=st[id<<1]+st[(id<<1)|1];
    }
    int Sum(int L, int R, int l, int r, int id=1)
    {
        if(r<L||R<l)return 0;
        if(L<=l&&r<=R)return st[id];
        int mid = (l+r)/2;
        return Sum(L,R,l,mid,(id<<1))+Sum(L,R,mid+1,r,(id<<1)|1);
    }
    void mod(int pos, int d, int l, int r, int id=1)
    {
        if(l==r&&l==pos)
        {
            st[id]+=d;
            return;
        }
        int mid = (l+r)/2;
        if(pos>mid)mod(pos,d,mid+1,r,(id<<1)|1);
        else mod(pos,d,l,mid,(id<<1));
        up(id);
    }
    //helper functions
    int Sum(int L, int R)
    {
        return Sum(L,R,1,N);
    }
    void mod(int pos, int d)
    {
        mod(pos,d,1,N);
    }
    int N;
    static const int ST_MAXN = 400005;
    int st[ST_MAXN*4];
}segt;

int conv(ll x)
{
    return lower_bound(ALL(vals),x)-vals.begin()+1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>K;
    FOR(i,1,N)
    {
        cin>>A[i];
        A[i]-=K;
        psum[i]=psum[i-1]+A[i];
        vals.pb(psum[i]);
        vals.pb(-psum[i]);
    }
    sort(ALL(vals));
    vals.resize( unique(ALL(vals))-vals.begin() );
    int V = vals.size();
    ll Ans=0;
    //all ai -> 1~V
    segt.init(V);
    //FOR(i,0,V-1)cout<<vals[i]<<' ';
    //cout<<'\n';
    FOR(i,1,N)
    {
        int d = conv(psum[i]);
        Ans+=segt.Sum(1,d);
        if(psum[i]>=0)Ans++;
        segt.mod(conv(psum[i]),1);
    }
    cout<<Ans<<'\n';

    return 0;
}
