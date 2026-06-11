#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;




int n;
ll a,b;



bool test(ll x, vector<ll> h) {
    ll boost = a-b;
    ll need = 0;
    for (int i=0; i<n; i++) {
	h[i] -= x*b;
	if (h[i]<0) continue;
	need += (h[i]+boost-1)/boost;
    }
    return need<=x;    
}

vector<ll> h;
ll ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n>>a>>b;
    h.resize(n);
    for (int i=0; i<n; i++) {
	cin>>h[i];
    }

    ll lo=0;
    ll hi = 1e10;
    while (hi-lo>1) {
	ll mid = (lo+hi)/2;
	if (test(mid, h)) {
	    hi=mid;
	} else {
	    lo=mid;
	}
    }
    
    cout<<hi<<endl;
  

    return 0;
}
