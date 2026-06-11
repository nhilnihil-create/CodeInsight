#include <bits/stdc++.h>
#define MAXN 100100
#define pii pair<int, int>
#define pb push_back
typedef long long ll;

using namespace std;

ll n, a, b, h[MAXN];

bool check(ll x){
	ll t = 0;
	for(int i = 0; i < n; i++){
		ll y = x * b;
		if(y / x != b) continue;
		if(h[i] <= x * b) continue;
		t += (h[i] - x * b + (a - b) - 1) / (a - b);
	}
	return t <= x;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++){
    	cin >> h[i];
    }
    ll l = 1, r = 1e18;
    while(l < r){
    	ll mid = (l + r) / 2;
    	if(check(mid)) r = mid;
    	else l = mid + 1;
    }
    cout << l;
}