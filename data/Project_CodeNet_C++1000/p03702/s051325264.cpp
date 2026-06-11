#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
int arr[maxn];
int n,a,b;
bool check(ll mid) {
	int base = (1e9 / b + 1 >= mid ? b * mid : 1e9) , dif = a - b;
	for(int i=1;i<=n;i++)
		if(arr[i] > base)
			mid -= (arr[i] - base - 1) / dif + 1;
	return mid >= 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> a >> b;
	for(int i=1;i<=n;i++)
		cin >> arr[i];
	ll l = 1 , r = (ll)1e14 , mid;
	while(true) {
		if(r - l < 3) {
			for(mid=r;mid>=l && check(mid);mid--);
			mid++;
			break;
		}
		mid = (l+r)>>1;
		if(check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << mid << endl;
	return 0;
}
