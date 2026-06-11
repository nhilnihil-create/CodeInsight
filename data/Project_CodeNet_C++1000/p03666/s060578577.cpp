#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    bool ok = false;
    if(a > b)swap(a,b);
    n--;
    ll mi = a, ma = a;
    while(n--){
    	ma -= c;
    	mi -= d;
    	if((b - ma) <= n * d && (b - mi) >= n * c) ok = true;
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
