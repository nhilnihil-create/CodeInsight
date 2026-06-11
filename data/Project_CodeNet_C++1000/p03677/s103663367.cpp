#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
template<class T>void chmax(T &a,T b){if(a<b)a=b;}
template<class T>void chmin(T &a,T b){if(a>b)a=b;}
constexpr int INF=1000000000000000000;
constexpr int mod=1000000007;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
bool prime(int a){
    if(a==1)return false;
    for(int i=2;i*i<=a;i++){
        if(a%i==0)return false;
    }
    return true;
}
vector<int>kaijo;
void init_fact(int n){
    kaijo.resize(n+1);
    kaijo[0]=1;
    for(int i=1;i<=n;i++){
        kaijo[i]=kaijo[i-1]*i;
        kaijo[i]%=mod;
    }
}
int modpow(int a,int b){
    if(b==0)return 1;
    if(b%2)return modpow(a,b-1)*a%mod;
    int memo=modpow(a,b/2);
    return memo*memo%mod;
}
int comb(int a,int b){
    //if(!kaijo[0])init_fact();
    return kaijo[a]*modpow(kaijo[a-b],mod-2)%mod*modpow(kaijo[b],mod-2)%mod;
}
int inv(int x){
    x=modpow(x,mod-2);
    return x;
}
bool kosa(double ax,double ay,double bx,double by,double cx,double cy,double dx,double dy){
    double ta=(cx-dx)*(ay-cy)+(cy-dy)*(cx-ax);
    double tb=(cx-dx)*(by-cy)+(cy-dy)*(cx-bx);
    double tc=(ax-bx)*(cy-ay)+(ay-by)*(ax-cx);
    double td=(ax-bx)*(dy-ay)+(ay-by)*(ax-dx);
    return tc*td<0&&ta*tb<0;
}
struct Segtree{
    int siz=1;
    vector<int>dat,laz;
    Segtree(int n){
        while(siz<n)siz*=2;
        dat.resize(siz*2-1,0);
        laz.resize(siz*2-1,0);
    }
    void eval(int k,int l,int r){
        if(laz[k]!=0){
            dat[k]+=laz[k];
            if(r-l>1){
                laz[2*k+1]+=laz[k]/2;
                laz[2*k+2]+=laz[k]/2;
            }
            laz[k]=0;
        }
    }
    void update(int a,int b,int x,int k=0,int l=0,int r=-1){
        if(r==-1)r=siz;
        eval(k,l,r);
        if(b<=l||r<=a)return;
        if(a<=l&&r<=b){
            laz[k]+=(r-l)*x;
            eval(k,l,r);
            return;
        }
        update(a,b,x,2*k+1,l,(l+r)/2);
        update(a,b,x,2*k+2,(l+r)/2,r);
        dat[k]=dat[2*k+1]+dat[2*k+2];
    }
    int query(int a,int b,int k=0,int l=0,int r=-1){
        if(r==-1)r=siz;
        if(b<=l||r<=a)return 0;
        eval(k,l,r);
        if(a<=l&&r<=b)return dat[k];
        int vl=query(a,b,2*k+1,l,(l+r)/2);
        int vr=query(a,b,2*k+2,(l+r)/2,r);
        return vl+vr;
    }
};
int n,m,a[100010],sum,ans,now;
signed main(){
    cin>>n>>m;
    rep(i,n){
        cin>>a[i];
        a[i]--;
    }
    Segtree seg(m);
    rep(i,n-1){
        int A=a[i],B=a[i+1];
        if(A<B){
            if(A+2<m)seg.update(A+2,B+1,1);
            if(B+1<m)seg.update(B+1,B+2,-(B-A-1));
            sum+=B-A;
        }
        if(A>B){
            if(A+2<m)seg.update(A+2,m,1);
            seg.update(0,B+1,1);
            seg.update(B+1,B+2,-(B+m-A-1));
            sum+=B+m-A;
            now+=m-A-1;
        }
    }
    ans=now;
    for(int i=1;i<m;i++){
        now+=seg.query(i,i+1);
        chmax(ans,now);
    }
    cout<<sum-ans<<endl;
    return 0;
}