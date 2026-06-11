#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b){
	while(a){
		//cout << a << " " << b << "---> ";
		swap(a,b%=a);
		//cout << a << " " << b << "\n";
	}
	return b;
	}

int main(){
	ll n,x; 
	cin >> n >> x;
	cout << 3*(n-gcd(n,x));
	return 0;
	}

