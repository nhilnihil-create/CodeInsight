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

int main(){
    ll n,ans=1,p; cin>>n;
    vector<ll> a(n,0);
    rep(i,n) cin>>a[i];
    p=a[0];
    for(ll i=2;i<n;i++){
        if((a[i-1]-p)*(a[i]-a[i-1])<0){
            ans++;
            p=a[i];
            i++;
        }
    }
    cout<<ans<<endl;
}