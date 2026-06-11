/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	if (a[0] + a[1] == a[2])
		cout << "Yes";
	else
		cout << "No";
}
