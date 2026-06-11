// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで
// -fsanitize=undefinedでオーバーフロー検出,オーバーフローする入力を投げるとよい
#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
bool is_prime(int n) {
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) return false;
    }
    if(n==1) return false;
    return true;
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
 
    ll a,b,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    string str,stra="CODEFESTIVAL2016";
    ll k;
    ll w,x,y;
    ll h;
    cin>>w>>h>>n;
    ll za[h][w];
    ll l=0;
    ll r=w;
    ll u=h;
    d=0;
    rep(_,n){
        cin>>x>>y>>b;
        if(b==1){
            l=max(l,x);
        }if(b==2){
            r=min(r,x);
        }if(b==3){
            d=max(d,y);
        }if(b==4){
            u=min(u,y);
        }
    }
    //cout<<r<<" "<<l<<" "<<u<<" "<<d<<endl;
    if(l>=r||d>=u) cout<<0<<endl;
    else cout<<(r-l)*(u-d)<<endl;
    return 0;
}
