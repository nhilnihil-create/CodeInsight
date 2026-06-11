#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout << fixed << setprecision(20);

    ll n,x;
    cin>>n>>x;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans = 1e18;
    for(int i=0;i<n;i++){
        ll ret = 0;
        multiset<ll> st;
        for(int j=0;j<=i;j++){
            st.insert(a[j]);
        }
        for(int j=0;j<n;j++){
            int t = (i+j+1)%n;
            ret += *st.begin();
            st.erase(a[j]);
            st.insert(a[t]);
        }
        
        ans = min(ans, ret + x*i);
    }
    cout << ans << endl;
}