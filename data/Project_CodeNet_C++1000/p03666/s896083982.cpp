#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    ll n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    //以下を考えても同値
    b-=a;
    a=0;
    //
    bool f=false;
    for(int i=0;i<n;i++){
        ll up=(n-1-i)*d-i*c;
        ll lw=(n-1-i)*c-i*d;
        if(lw<=b&&b<=up) f=true;
    }
    cout<<(f?"YES":"NO")<<endl;
    return 0;
}
