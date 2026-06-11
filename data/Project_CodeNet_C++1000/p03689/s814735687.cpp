#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
#define fore(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define rep(i,n) fore(i,0,(n)-1)
#define rfore(i,a,b) for(ll i=(ll)(b);i>=(ll)(a);--i)
#define rrep(i,n) rfore(i,0,(n)-1)
#define all(x) (x).begin(),(x).end()
const ll INF=1001001001;
const ll LINF=1001001001001001001;
const ll D4[]={0,1,0,-1,0};
const ll D8[]={0,1,1,0,-1,-1,1,-1,0};
template<class T>
bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>
bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
const string YES = "Yes";
const string NO = "No";

void solve(long long H, long long W, long long h, long long w){
    if(H%h==0&&W%w==0){
        cout<<NO<<endl;
        return;
    }

    cout<<YES<<endl;
    ll v=(ll)1e9/(h*w);
    vvl ans(H,vl(W));
    rep(i,H){
        rep(j,W){
            if(j>0)cout<<" ";
            if((i+1)%h|(j+1)%w)cout<<v;
            else cout<<-(v*(h*w-1)+1);
        }
        cout<<endl;
    }

}

int main(){
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    long long h;
    scanf("%lld",&h);
    long long w;
    scanf("%lld",&w);
    solve(H, W, h, w);
}
