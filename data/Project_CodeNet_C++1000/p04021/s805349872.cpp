#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
/// khodaya komak kon
/// ya navid navid
const int N=1e6+10,M=21,mod=1e9+7;
ll a[N];
map <int,int> mp;
int32_t main(){
    ll n;
    cin >> n;
    ll ans=0;
    vector <int> b;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        b.pb(a[i]);
    }
    sort(b.begin(),b.end());
    for (int i=1;i<=n;i++){
        mp[b[i-1]]=i;
    }
    for (int i=1;i<=n;i++){
        a[i]=mp[a[i]];
    }
    for (int i=1;i<=n;i++){
        if (a[i]%2!=i%2){
            ans++;
        }
    }
    cout << ans/2;
}
