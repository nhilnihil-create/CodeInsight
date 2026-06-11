#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,x;cin >> n >> x;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ll ans=0;
    for(int i=1;i<n;i++){
        if(a[i-1]+a[i]>x){
            ll u=a[i-1],v=a[i];
            ans+=u+v-x;
            if(a[i-1]>=x){
                a[i]=0;
                a[i-1]=x;
            }
            else{
                a[i]=x-u;
            }
        }
    }
    cout << ans << endl;
}