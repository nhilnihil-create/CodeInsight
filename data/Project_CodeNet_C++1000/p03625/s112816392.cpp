#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;


int main(){
    fast_io

    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    sort(a.begin(), a.end(), greater<ll>());

    ll ans=1;
    int cnt=0;

    rep(i,n){
        
        if(a[i]==a[i+1]){
            ans*=a[i];
            cnt++;
            ++i;
        }
        if(cnt==2){
            cout<<ans<<endl;
            return 0;
        }
        //cout<<a[i]<<" "<<cnt<<" "<<ans<<endl;
    }
    cout<<0<<endl;
    
    return 0;
}
