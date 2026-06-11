#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	ll n, a, b;
	cin>>n>>a>>b;
	if(a > b){
		cout<<0;
	}else if(a == b){
		cout<<1;
	}else if(n == 1){
		cout<<0;
	}else{
		cout<<(b - a)*(n - 2) + 1;
	}

	return 0;
}