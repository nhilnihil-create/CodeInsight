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

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n;cin>>n;
    vector<ll> a(n);
    ll sum=0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    ll plus_per_sousa=n*(n+1)/2;
    if(sum%plus_per_sousa!=0){
        cout<<"NO"<<endl;
        return 0;
    }
    ll k=sum/plus_per_sousa;

    bool f=true;
    ll ans=0;
    rep(i,n){
        ll bunsi=a[i]-a[(i+1)%n]+k;
        if(bunsi<0){
            f=false;break;
        }
        if((bunsi%n)!=0){
            f=false;break;
        }
        ans+=bunsi/n;
    }
    if(f)    cout<<"YES"<<endl;
    else                cout<<"NO"<<endl;
    return 0;
}
