#include <bits/stdc++.h>
using namespace std;
#define int long long
#define stoi stoll
using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;
#define ALL(c) begin(c),end(c)
#define RALL(c) rbegin(c),rend(c)
#define ITR(i,b,e) for(auto i=(b);i!=(e);++i)
#define FORE(x,c) for(auto &x:c)
#define REPF(i,a,n) for(int i=a,i##len=(int)(n);i<i##len;++i)
#define REP(i,n) REPF(i,0,n)
#define REPR(i,n) for(int i=(int)(n);i>=0;--i)
#define SZ(c) ((int)c.size())
#define CONTAIN(c,x) (c.find(x)!=end(c))
#define OUTOFRANGE(y,x,h,w) ((y)<0||(x)<0||(y)>=(h)||(x)>=(w))
#define dump(...)
const signed INF_=1001001001; const ll INF=1001001001001001001LL;
const int DX[9]={0,1,0,-1,1,1,-1,-1,0},DY[9]={-1,0,1,0,-1,1,1,-1,0};
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) {
    ITR(i,begin(v),end(v))os<<*i<<(i==end(v)-1?"":" ");return os;}
template<class T> istream& operator>>(istream &is,vector<T> &v) {
    ITR(i,begin(v),end(v)) is>>*i;return is;}
template<class T,class U> istream& operator>>(istream &is, pair<T,U> &p) {
    is>>p.first>>p.second;return is;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}
template<class T> using heap=priority_queue<T,vector<T>,greater<T>>;
struct{template<class T> operator T(){T x;cin>>x;return x;}} IN;
struct before_main_function {
    before_main_function() {
        cin.tie(0);ios::sync_with_stdio(false);
        cout<<setprecision(15)<<fixed;
        #define endl "\n"
    }
} before_main_function;
//------------------8<------------------------------------8<--------------------

signed main() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    REP(i,n) {
        cin>>a[i];
        a[i]--;
    }

    vector<int> b(2*m+2,0);
    REP(i,n-1) {
        int l=a[i]+2,r=a[i+1];
        if(a[i]>a[i+1]) {
            r=a[i+1]+m;
        }
        b[l]+=1;
        b[r+1]-=(r-l)+2;
        b[r+2]+=(r-l)+1;
    }
    REP(i,2*m+1) b[i+1]+=b[i];
    REP(i,2*m+1) b[i+1]+=b[i];
    REP(i,m) b[i]+=b[i+m];

    int mx=0,X=0;
    REP(i,m) if(chmax(mx,b[i])) X=i;


    int ans=0;
    REP(i,n-1) {
        int tmp=0;
        if(a[i]<a[i+1]) {
            if(a[i]<X && X<=a[i+1]) {
                tmp=1+a[i+1]-X;
            } else {
                tmp=a[i+1]-a[i];
            }
        } else {
            if(a[i]<X) {
                tmp=1+a[i+1]-(X-m);
            } else if(X<=a[i+1]) {
                tmp=1+a[i+1]-X;
            }else {
                tmp=(a[i+1]+m)-a[i];
            }
        }
        ans+=tmp;
    }
    cout<<ans<<endl;
    return 0;
}

