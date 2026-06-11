#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll dp[105][100005];
int main(){
    int n;
    cin>>n;
    V<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ll L;
    cin>>L;
    for(int i=0;i<n;i++){
        int ite=lower_bound(all(a),a[i]+L+1)-a.begin();
        dp[1][i]=ite-1;
    }
    for(int i=1;i<100;i++){
        for(int j=0;j<n;j++){
            dp[i+1][j]=dp[i][dp[i][j]];
        }
    }
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        a--;b--;
        if(a>b)swap(a,b);
        ll l=0,r=(1e5)+10;
        while(r-l>1){
            ll mid=(l+r)/2;
            int now=a;
            ll tmp=mid;
            int cnt=1;
            bool ok=false;
            while(tmp){
                if(tmp&1)now=dp[cnt][now];
                tmp>>=1;
                if(now>=b){
                    ok=true;
                    break;
                }
                cnt++;
            }
            if(ok)r=mid;
            else l=mid;
        }
        cout<<r<<"\n";
    }
}