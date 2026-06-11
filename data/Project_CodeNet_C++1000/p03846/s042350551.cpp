/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int M = 1000 * 1000 * 1000 + 7;

int32_t main(){
	int n;
	cin >> n;
	int a[n], cnt[n] = {};
	for (int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	bool f = true;
	for (int i = (n) % 2 + 1; i < n; i += 2){
		if (cnt[i] != 2)
			f = false;
	}
	if (n % 2 == 1){
		if (cnt[0] != 1)
			f = false;
	}
	if (!f){
		cout << 0;
	}else{
		int x = 1;
		for (int i = 0; i < n / 2; i++){
			x *= 2;
			x %= M;
		}
		cout << x;
	}
}
