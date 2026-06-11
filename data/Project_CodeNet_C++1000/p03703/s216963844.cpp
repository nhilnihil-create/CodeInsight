#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;
ll arr[maxn];
int SZ,bit[maxn];
inline int lowbit(int x) {
	return x&-x;
}
void add(int pos) {
	while(pos <= SZ) {
		bit[pos]++;
		pos += lowbit(pos);
	}
}
int sum(int pos) {
	int ret = 0;
	while(pos > 0) {
		ret += bit[pos];
		pos -= lowbit(pos);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin >> n >> k;
	vector<ll> dct = {0};
	for(int i=1,val;i<=n;i++) {
		cin >> val;
		arr[i] = arr[i-1] + val - k;
		dct.push_back(arr[i]);
	}
	sort(dct.begin(),dct.end());
	dct.resize(unique(dct.begin(),dct.end())-dct.begin());
	SZ = (int)dct.size();
	ll ans = 0;
	for(int i=0;i<=n;i++) {
		int idx = lower_bound(dct.begin(),dct.end(),arr[i])-dct.begin() + 1;
		ans += sum(idx);
		add(idx);
	}
	cout << ans << endl;
	return 0;
}
