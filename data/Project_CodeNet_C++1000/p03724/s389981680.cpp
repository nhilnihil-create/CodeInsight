#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define LINF (ll)1e18
#define INF (int)1e9
#define ll_1e9 (ll)1e9
using namespace std;


int main(){
    ll n,m;
    cin >> n >> m;
    ll cnt[n+1] = {};
    ll a[m],b[m];
    rep(i,0,m){
        cin >> a[i] >> b[i];
        cnt[a[i]]++;
        cnt[b[i]]++;
    }


    rep(i,0,n){
        if(cnt[i] % 2){
            cout << "NO" << endl;
            break;
        }
        else if(i == n-1){
            cout << "YES" << endl;
        }
    }

    return 0;
}
