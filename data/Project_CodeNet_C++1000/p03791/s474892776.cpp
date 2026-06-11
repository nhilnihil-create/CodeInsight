#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n),d(n,0);
    rep(i,n) cin >> a[i];
    ll u=0;
    rep(i,n){
        if (i==0) u+=a[i];
        else{
            d[i]=d[i-1];
            if (u==0){
                d[i]++;
                u+=2;
            }
            u+=a[i]-a[i-1]-2;
        }
    }
    ll ans=1;
    rep(i,n){
        (ans*=n-i-d[n-1-i])%=MOD;
    }
    cout << ans << endl;
}
