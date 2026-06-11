#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n = 50;
	ll k;
	cin >> k;
	ll a[52];
	for(int i = 0 ; i < n ; i ++){
		a[i] = n-1+k/n;
	}
	for(int i = 0 ; i < k%n ; i ++){
		a[i] -= k%n;
		a[i] += n+1;
	}
	for(int i = k%n ; i < n ; i ++){
		a[i] -= k%n;
	}
	cout << n << endl;
	for(int i = 0 ; i < n ; i ++){
		cout << a[i] << ((i+1==n)?'\n':' ');
	}
}

