#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
struct SegTree{
    int n;
    vector <int> node;
    SegTree(vector <int> v){
        int sz = v.size();
        n = 1;
        while(n<sz) n*=2;
        node.resize(2*n-1, INF);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i]; //一番下側
        for(int i=n-2;i>=0;i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }
    void update(int number, int val){
        number += n-1;
        node[number]= val;
        while(number>0){
            number=(number-1)/2;
            node[number] = min(node[number*2+1], node[number*2+2]);
        }
    }
    int getmin(int a, int b, int k=0, int l = 0, int r = -1){
        if(r<0) r=n;
        if(r<=a||l>=b) return INF;
        if(a <= l&& r<=b) return node[k];
        int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};
//参考:http://tsutaj.hatenablog.com/entry/2017/03/29/204841
signed main(void){
    int n,x; cin>>n>>x;
    vector <int> a(n);
    int ans = 0;
    rep(i,n) {cin>>a[i]; ans += a[i];}
    SegTree seg = SegTree(a);
    for(int i=0;i<=n;i++){
        //i魔法を唱える回数
        int addmagic = x*i;
        int cnt = 0;
        rep(j,n){
            int rem = j-i;
            if(rem<0){
                int mi = seg.getmin(0, j+1);
                mi = min(mi, seg.getmin(n+rem, n));
                cnt += mi;
            }else{
                int mi = seg.getmin(j-i, j+1);
                cnt += mi;
            }
        }
        chmin(ans, addmagic + cnt);
    }
    cout<<ans<<endl;
}
