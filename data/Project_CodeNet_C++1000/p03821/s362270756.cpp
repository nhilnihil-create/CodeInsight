#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793




int main(){
    ll ans=0;
    int n;
    cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n)cin >> a.at(i) >> b.at(i);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    rep(i,n){
        ll x=a.at(i)+ans;
        ll psh;
        if((x%b.at(i))==0)psh=0;
        else psh=b.at(i)-(x%b.at(i));
        ans+=psh;
    }
    cout << ans << endl;
}
       