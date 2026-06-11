#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mit map<int,int>::iterator
#define sit set<int>::iterator
#define itrm(g,x) for(mit g=x.begin();g!=x.end();g++)
#define itrs(g,x) for(sit g=x.begin();g!=x.end();g++)
#define ltype int
#define rep(i,j,k) for(ltype(i)=(j);(i)<=(k);(i)++)
#define rap(i,j,k) for(ltype(i)=(j);(i)<(k);(i)++)
#define per(i,j,k) for(ltype(i)=(j);(i)>=(k);(i)--)
#define pii pair<int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
#define fastio ios::sync_with_stdio(false)
const int inf=0x3f3f3f3f,mod=1000000007;
const double pi=3.1415926535897932,eps=1e-6;
void chmax(int &x,int y){if(x < y) x = y;}
void chmin(int &x,int y){if(x > y) x = y;}
int n,cnt,k;ll a[200005],sum[200005],ans;
map<ll,int> m;
struct segtree{
    int dat[525000],n;
    void build(int nn)
    {
        n=1;
        while(n<=nn) n<<=1;
    }
    void update(int k,int a){
        k+=n-1;
        dat[k]+=a;
        while(k>0){
            k=(k-1)/2;
            dat[k] = dat[(k<<1)+1]+dat[(k<<1)+2];
        }
    }
    int query(int l,int r){
        return query(l,r+1,0,0,n);
    }
    int query(int a,int b,int k,int l,int r){
        if(r<=a||b<=l) return 0;
        if(a<=l&&r<=b) return dat[k];
        return query(a,b,(k<<1)+1,l,(l+r)>>1)+query(a,b,(k<<1)+2,(l+r)>>1,r);
    }
}seg;
int main()
{
    fastio;
    cin>>n>>k;
    seg.build(n);
    rep(i,1,n) cin>>a[i];
    rep(i,1,n) sum[i] = sum[i-1] + a[i] - k, m[sum[i]] = 0;
    m[0] = 0;
    for(map<ll,int>::iterator it = m.begin();it != m.end();it++) it->se = ++cnt;
    rep(i,1,n) sum[i] = m[sum[i]];
    seg.update(m[0],1);
    rep(i,1,n) {
        ans += seg.query(1,sum[i]);
        seg.update(sum[i],1);
    }
    cout<<ans<<'\n';
    return 0;
}