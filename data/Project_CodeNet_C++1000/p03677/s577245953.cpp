#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7,ohara=1e6+10;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl
#define doublecout(a) cout<<fixed<<setprecision(15)<<a<<endl;
#define Cerr(x) cerr<<(x)<<endl
#define fi first
#define se second
#define P pair<ll,ll> 
#define m_p make_pair
#define V vector<ll> 
#define U_MAP unordered_map<ll,ll>

ll n,cnt,ans,a[ohara],b,c,d,tmp,tmpp,m,h,w,x,y,sum,pos,k;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

//------ 自分を天才だと信じる ------

struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;
 
public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
 
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }
 
    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }
 
    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }
 
    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};

int main(void){
        cin.tie(0);
        cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    rep(i,n)cin>>a[i];
    LazySegmentTree seg1(vector<ll>(100000+10,0));
    LazySegmentTree seg2(vector<ll>(100000+10,0));
    rep(i,n-1){
        if(a[i]<a[i+1]){
            seg1.add(0,a[i],a[i+1]-a[i]);
            seg1.add(a[i],a[i+1],1+a[i+1]);
            seg2.add(a[i],a[i+1],1);
            seg1.add(a[i+1],100000,a[i+1]-a[i]);
        }
        else{
            seg1.add(0,a[i+1],a[i+1]+1);
            seg2.add(0,a[i+1],1);
            seg1.add(a[i+1],a[i],m-a[i]+a[i+1]);
            seg1.add(a[i],100000,m+a[i+1]+1);
            seg2.add(a[i],100000,1);
        }
    }
    ans=LINF;
    rrep(i,1,m+1){
        cnt=seg1.getsum(i-1,i);
        cnt-=i*seg2.getsum(i-1,i);
        ans=min(ans,cnt);
    }
    Cout(ans);
    return 0;
}
