#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v1;
typedef vector<v1> v2;

typedef vector<vector<ll>> graph;

const ll INF = 1ll << 50;
const ll mod = 1000000007;

ll n;
ll a[100000];
ll b[100000];

int main(){
    cin >> n;
    for(ll i = 0;i < n;i++) cin >> a[i] >> b[i];
    cout << a[min_element(b,b+n)-b]+(*min_element(b,b+n)) << endl;
}
