#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	sort(a.begin(), a.end());
	if(a.back() < k){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	int g = a[0];
	rep(i, n - 1) g = gcd(g, a[i + 1]);

	if(k % g == 0){
		cout << "POSSIBLE" << endl;
	}else{
		cout << "IMPOSSIBLE" << endl;
	}
}
