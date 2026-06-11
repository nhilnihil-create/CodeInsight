#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
 
const ll oo = 1e15 + 7;
const int mod = 1e9 + 7, maxn = (2 * 1e3) + 10;
const long double PI = acos(-1);

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;

    cin >> n >> m;

    vector<ll> a(m), b(m), c(m), dist(n, oo);
    bitset<maxn> neg(0);

    for (int i=0; i<m; i++){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
        c[i]*=-1;
    }

    dist[0] = 0;

    for (int loop=0; loop<n-1; loop++){
        for (int i=0; i<m; i++){
            if (dist[a[i]] == oo) continue;
            
            if (dist[b[i]] > dist[a[i]] + c[i]){
                dist[b[i]] = dist[a[i]] + c[i];
            }
        }
    }

    ll ans = dist[n-1];

    for (int loop = 0; loop < n-1; loop++){
        for (int i=0; i<m; i++){
            if (dist[a[i]] == oo) continue;
            if (dist[b[i]] > dist[a[i]] + c[i]){
                neg[b[i]] = 1;
                dist[b[i]] = dist[a[i]] + c[i];
            }
            if (neg[a[i]]) neg[b[i]] = 1;
        }
    }

    if (neg[n-1]) cout << "inf" << endl;
    else cout << -ans << endl;
    return 0;
}