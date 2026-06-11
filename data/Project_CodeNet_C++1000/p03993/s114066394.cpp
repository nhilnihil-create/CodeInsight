#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> a(n);
	rep(i, n){
		cin >> a[i];
		a[i]--;
	}

	int ans = 0;
	vector<bool> used(n, false);
	rep(i, n){
		if(!used[a[i]] && a[a[i]] == i){
			used[i] = true;
			used[a[i]] = true;
			ans++;
		} 
	}

	cout << ans << endl;
}
