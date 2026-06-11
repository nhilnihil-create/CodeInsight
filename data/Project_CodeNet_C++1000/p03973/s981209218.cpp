#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    ll c = 1, ans = 0;
    for(int i=0;i<n;i++){
    	if(i == 0) ans += a[i] - 1, a[i] = 1;
    	if(c == a[i]){
    		c++;
    		continue;
    	}
    	if(c > a[i]) continue;
    	if(a[i] % c == 0){
    		ans++;
    		a[i] -= (c + 1);
    		i--;
    		continue; 
    	}
    	ans += a[i] / c;
    }
    cout << ans << endl;
    return 0;
}
