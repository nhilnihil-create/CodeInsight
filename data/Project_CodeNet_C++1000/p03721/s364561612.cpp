#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
 
const int oo = 1e9 + 7;
const int mod = 1e9 + 7, maxn = 200200;
const long double PI = acos(-1);

ll n, m, k;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;

    vector<pii> v(n);

    for (int i=0; i<n; i++){
        cin >> v[i].ff >> v[i].ss;
    }

    sort(all(v));

    int id = 0;

    while (k > 0){
        k-=v[id++].ss;
    }

    cout << v[--id].ff << endl;
    
    return 0;
}