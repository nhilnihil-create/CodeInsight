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
    vector<int> dat;
    public:
    BinaryIndexedTree(int n_){
        dat.resize(++n_,0);
    }
    void add(int a,int w){
        for (int i=a;i<=dat.size();i+=i&-i) dat[i]+=w;
    }
    int sum(int a){
        int res=0;
        for (int i=a;i>0;i-=i&-i) res+=dat[i];
        return res;
    }
    int binarysearch(int w){
        if (w<=0) return 0;
        int x=0;
        int n=1;
        while(n*2<=dat.size()) n*=2;
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
    ll N,K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i,N){
        cin >> a[i];
        a[i]-=K;
    }
    vector<ll> sum(N+1);
    sum[0]=0;
    rep(i,N) sum[i+1]=sum[i]+a[i];
    vector<ll> compress=sum;
    sort(compress.begin(),compress.end());
    compress.erase(unique(compress.begin(),compress.end()),compress.end());
    rep(i,N+1) sum[i]=lower_bound(compress.begin(),compress.end(),sum[i])-compress.begin()+1;
    ll s=compress.size();
    BinaryIndexedTree BIT(++s);
    ll ans=0;
    rep(i,N+1){
        ans+=BIT.sum(sum[i]);
        BIT.add(sum[i],1);
    }
    cout << ans << endl;
}