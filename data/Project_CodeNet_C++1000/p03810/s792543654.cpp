//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, a[maxn], s;
string st[2] = {"First", "Second"};

int main(){
    fast_io;

    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n % 2 == 0){
        for(ll i = 0; i < n; i++){
            s += a[i];
        }
        if(s & 1) cout << "First";
        else cout << "Second";
        return 0;
    }
    ll t = 0;
    while(true){
        s = 0;
        for(ll i = 0; i < n; i++){
            s += a[i];
        }
        if(s % 2 == 0){
            cout << st[t];
            return 0;
        }
        ll x = -1;
        for(ll i = 0; i < n; i++){
            if((a[i] & 1) == 1 && a[i] > 1) x = i;
        }
        if(x == -1){
            cout << st[1 - t];
            return 0;
        }
        a[x]--;
        ll g = 0;
        for(ll i = 0; i < n; i++){
            g = __gcd(g, a[i]);
        }
        for(ll i = 0; i < n; i++){
            a[i] /= g;
        }
        t = 1 - t;
    }

    return 0;
}
