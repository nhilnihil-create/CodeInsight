#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(),a.end());
	ll now = a[0];
	int ans = 0;
	int cnt = 0;

	for(int i = 1; i < n; i++){
		if(2*now < a[i]){
			ans += cnt+1;
			cnt = 0;
		}
		else cnt++;
		now += a[i];
	}

	ans = n-ans;
	
	cout << ans << endl;
	return 0;
}