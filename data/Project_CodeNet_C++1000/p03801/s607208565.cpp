#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;

int n, a[100005], itr = 1, mx = 0, sum, num;
ii b[100005];
set<int> se;

signed main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i].fi = a[i];
		b[i].se = i;
	}
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; i++){
		if(a[i] <= mx){
			cout << 0 << "\n";
			se.erase(i);
			continue;
		}
		sum = 0;
		while(b[itr].fi < a[i]){
			if(b[itr].se > i){
				sum += b[itr].fi - mx;
				se.insert(b[itr].se);
			}
			itr++;
		}
		//cout << num << " " << sum << "\n";
		cout << (a[i] - mx) * (n - i + 1 - se.size()) + sum << "\n";
		mx = a[i];
	}
}
