#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

struct BinaryIndexedTree{
    private:
    int n;
    vector<int> dat;
    public:
    BinaryIndexedTree(int n_){
        n=1;
        while(n<n_) n*=2;
        dat.resize(n,0);
    }
    void add(int a,int w){
        for (int i=a;i<=n;i+=i&-i) dat[i]+=w;
    }
    int sum(int a){
        int res=0;
        for (int i=a;i>0;i-=i&-i) res+=dat[i];
        return res;
    }
    int binarysearch(int w){
        if (w<=0) return 0;
        int x=0;
        for (int k=n;k>0;k/=2){
            if (x+k<=n&&dat[x+k]<w){
                w-=dat[x+k];
                x+=k;
            }
        }
        return x;
    }
};

int main(){
    int N,M;
    cin >> N >> M;
    vector<Pii> range(N);
    BinaryIndexedTree BIT(M+10);
    rep(i,N){
        int l,r;
        cin >> l >> r;
        ++l,r+=2;
        BIT.add(l,1);
        BIT.add(r,-1);
        range[i]=Pii(r-l,l);
    }
    sort(range.begin(),range.end());
    reverse(range.begin(),range.end());
    int now=0;
    vector<int> ans(M);
    for (int i=M;i>0;--i){
        while(now<N&&range[now].first>=i){
            int l=range[now].second;
            int r=range[now].first+l;
            BIT.add(l,-1);
            BIT.add(r,1);
            ++now;
        }
        int cnt=now;
        for (int j=1;j<=M+1;j+=i) cnt+=BIT.sum(j);
        ans[i-1]=cnt;
    }
    rep(i,M) cout << ans[i] << endl;
}