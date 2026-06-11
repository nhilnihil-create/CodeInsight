#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    ll n, sum = 0, last = 2, x;
    cin >> n;
    ll arr[3*n];
    for(int i = 0; i < 3*n; i++) 
    	cin >> arr[i];
    sort(arr, arr+3*n);
    for(int i = 0; i < 3*n; i += 3) {
    	sum += arr[3*n-last];
    	last += 2;
    }
    cout << sum;

}
