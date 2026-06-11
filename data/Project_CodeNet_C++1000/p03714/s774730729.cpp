#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, a[300008], sum1[100008], sum2[100008];

int main() {
	cin >> n;
	for(ll i = 0; i < 3*n; i++){cin >> a[i];}
	sum1[0] = 0;
	sum2[n] = 0;
	priority_queue<ll, vector<ll>, greater<ll>> q1;
	priority_queue<ll> q2;
	
	for(ll i = 0; i < n; i++){sum1[0] += a[i]; q1.push(a[i]);}
	for(ll i = 2*n; i < 3*n; i++){sum2[n] += a[i]; q2.push(a[i]);}
	//
	for(ll i = 1; i <= n; i++){
		ll min = q1.top();
		if(a[n-1+i] > min){sum1[i] = sum1[i-1]+(a[n-1+i]-min); q1.pop(); q1.push(a[n-1+i]);}
		else{sum1[i] = sum1[i-1];}
	}
	for(ll i = 1; i <= n; i++){
		ll max = q2.top();
		if(a[2*n-1-(i-1)] < max){sum2[n-i] = sum2[n-i+1]+(a[2*n-1-(i-1)] - max); q2.pop(); q2.push(a[2*n-1-(i-1)]);}
		else{sum2[n-i] = sum2[n-i+1];}
	}
	
	ll best = sum1[0]-sum2[0];
	for(ll i = 1; i <= n; i++){best = max(sum1[i]-sum2[i], best);}
	//for(ll i = 0; i <= n; i++){cout << sum1[i];} cout << endl;
	//for(ll i = 0; i <= n; i++){cout << sum2[i];} cout << endl;
	cout << best;
	return 0;
}