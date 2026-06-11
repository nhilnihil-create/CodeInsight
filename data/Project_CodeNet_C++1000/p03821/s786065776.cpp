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
    ll n,ans=0; cin>>n;
    vector<ll> a(n,0),b(n,0);
    rep(i,n){
        cin>>a[i]>>b[i];
    }
    reverse(al(a)); reverse(al(b));
    rep(i,n){
        ans+=(b[i]-(a[i]+ans)%b[i])%b[i];
    }
    cout<<ans<<endl;
}