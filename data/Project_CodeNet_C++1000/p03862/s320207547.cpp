//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
    ll n,x,ans=0; cin>>n>>x;
    vector<ll> a(n,0);
    rep(i,n) cin>>a[i];
    if(a[0]>x){
        ans+=a[0]-x;
        a[0]=x;
    }
    for(ll i=1;i<n;i++){
        if(a[i-1]+a[i]>x){
        ans+=a[i-1]+a[i]-x;
        a[i]=x-a[i-1];
            }
        }
    cout<<ans<<endl;
}