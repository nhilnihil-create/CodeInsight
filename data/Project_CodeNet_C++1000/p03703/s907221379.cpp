#include<bits/stdc++.h> 
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int n, k;
ll a[200200], sum[200200];
set<ll> sums;
map<ll, ll> mp;
ll bit[200200];
int cnt = 0;
void update(int pos){
	while(pos <= cnt){
		bit[pos]++;
		pos += (pos & -pos); 
	}
}
ll query(int pos){
	ll sum = 0;
	while(pos >= 1){
		sum += bit[pos];
		pos -= (pos & -pos); 
	}
	return sum;
}

int main(){
	scanf("%d%d", &n, &k);
	ll ans = 0;
	rep(i, n){
		scanf("%d", &a[i]);
		a[i] -= k;
		sum[i+1] = sum[i] + a[i];
		sums.insert(sum[i]);
	}
	sums.insert(sum[n]);
	for(set<ll>::iterator it = sums.begin(); it != sums.end(); it++){
		mp[*it] = ++cnt;
	}
	rep(i, n+1) sum[i] = mp[sum[i]];
	rep(i, n+1){
		ans += query(sum[i]);
		update(sum[i]);	
	}
	cout << ans << endl;
	return 0;
}