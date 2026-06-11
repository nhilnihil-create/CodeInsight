#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	int n ,c , k;
	cin >> n >> c >>k;
	int arr[n] ;
	for (int i = 0 ; i < n ; i++) cin >> arr[i];
	sort (arr, arr+n);
	ll ans = 1;
	ll sum = arr[0] + k;
	int num = 1;

	for (int i = 1 ; i< n ; i++ ){
		if (arr[i] > sum || num >=c ){
			sum = arr[i] + k;
			num = 1;
			ans ++;
		}else {
			num++;
		}

	}
	cout << ans << endl;
}
