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
    ll n, m ;
    cin >> n >> m;
    bool a[n];
    vector<ll> num(n, 1);
    memset(a, 0, sizeof(a));
    a[0] = 1;
    ll x, y;
    for(int i =0 ;i<m;i++){
        cin >> x >> y;
        x--, y--;
        if(a[x]){
            num[x]--;
            num[y]++;
            if(num[x] >= 1){
                a[y] = true;
            }else{
                a[x] = false;
                a[y] = true;
            }
        }else{
            num[x]--;
            num[y]++;
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(a[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
