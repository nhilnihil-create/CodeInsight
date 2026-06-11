#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll t[3][3];
ll a[N];
vector <int> b;
map <int,int> mp;
int32_t main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        a[i]=x;
        b.pb(x);
    }
    sort(b.begin(),b.end());
    for (int i=0;i<b.size();i++){
        mp[b[i]]=i+1;
    }
    for (int i=1;i<=n;i++){
        a[i]=mp[a[i]];
        if (a[i]%2!=i%2){
            t[a[i]%2][i%2]++;
        }
    }
   // ll cnt=0;
    ll ans=0;
    for (int i=0;i<2;i++){
        for (int j=i+1;j<2;j++){
            ll z=min(t[i][j],t[j][i]);
            t[i][j]-=z;
            t[j][i]-=z;
    //        cnt+=t[i][j]+t[j][i];
            ans+=z;
        }
    }
  //  ans+=2*cnt/3;
    cout << ans << endl;


}
