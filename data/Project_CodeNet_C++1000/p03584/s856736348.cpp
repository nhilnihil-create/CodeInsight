#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define all(x) x.begin(), x.end()

const int mod = 998244353;

int main(){

	cin.tie(0);
	cin.sync_with_stdio(0);

	#ifdef Cyborg101
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	
	int n, k;
	cin >> n >> k;

	int a[n], b[n];

	for(int i = 0; i < n; ++i){
		cin >> a[i] >> b[i];
	}

	ll res = 0;
	for(int i = 0; i < n; ++i){
		if((a[i] | k) == k)
			res += b[i];
	}

	int cur = k;
	while(cur){
		int lsb = cur & -cur;
		cur ^= lsb; //remove lsb
		cur |= lsb - 1; // add whatever we can < lsb
		ll here = 0;
		for(int i = 0; i < n; ++i){
			if((a[i] | cur) == cur)
				here += b[i];
		}
		res = max(here, res);
		cur ^= lsb - 1;
	}

	cout << res << endl;

	return 0;
	
}