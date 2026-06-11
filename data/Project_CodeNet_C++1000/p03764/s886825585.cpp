#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define REP(i,a,n) for(int i=a;i<n;++i)
#define REPR(i,a,n) for(int i=a;i>n;--i)
#define RUP(a,b) ((a+b-1)/(b))
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define MOD 1000000007
#define INF LLONG_MAX/2

typedef long long ll;
typedef pair<int,int> Pii;
typedef tuple<int,int,int> Tiii;
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef vector<Pii> VPii;
typedef vector<string> Vs;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> void YesNo(T a) {cout<<(a?"Yes":"No")<<endl;}
template<class T> void YESNO(T a) {cout<<(a?"YES":"NO")<<endl;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
void uniq(Vi &v){sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());}
int ctoi(char c){if(c>='0'&&c<='9'){return c-'0';}return 0;}
bool comp(Pii a,Pii b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

void cntfill(Vi &x,int n){
    REP(i,0,n){
        if(i==0) x[i]=n;
        else x[i]=x[i-1]+(n-2*i);
    }
}


signed main(){cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    Vi a(n),b(m);
    REP(i,0,n) cin>>a[i];
    REP(i,0,m) cin>>b[i];
    
    sort(ALL(a));
    sort(ALL(b));
    Vi x(n-1),y(m-1);
    REP(i,0,n-1) x[i]=a[i+1]-a[i];
    REP(i,0,m-1) y[i]=b[i+1]-b[i];
    
    Vi cntx(n),cnty(m);
    cntfill(cntx,n-1);
    cntfill(cnty,m-1);

    int ansx=0,ansy=0;
    REP(i,0,n-1){
        ansx = (ansx+(x[i]*cntx[i])%MOD)%MOD;
    }
    REP(i,0,m-1){
        ansy = (ansy+(y[i]*cnty[i])%MOD)%MOD;
    }
    cout<<(ansx*ansy)%MOD<<endl;
    return 0;
}
