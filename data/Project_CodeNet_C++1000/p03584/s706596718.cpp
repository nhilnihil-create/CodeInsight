#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    ll a[n],b[n],sum,ans=0,maki;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    vector<ll> v;
    if(k==0)v.pb(k);
    while(k){
        v.pb(k);
        v.pb(k-1);
        k-=(k&(-k));
    }
    maki=v.size();
    for(int i=0;i<maki;i++){
        sum=0;
        for(int j=0;j<n;j++){
            if((a[j]|v[i])==v[i]){
                sum+=b[j];
            }
        }
        ans=max(ans,sum);
    }
    cout << ans<<endl;

    return 0;
}
