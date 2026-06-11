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
int32_t main(){
    ll n;
    cin >> n;
    ll ans=0;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    for (int i=0;i<n;i++){
        ans+=a[i]/2;
        if (a[i]%2==1 && a[i+1]>0){
            a[i+1]--;
            ans++;
        }
    }
    cout << ans;
}
