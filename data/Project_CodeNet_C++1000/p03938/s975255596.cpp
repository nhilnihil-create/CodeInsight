#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define MMAX (ll)(1e9)
#define MAX 20000

int main(){
	ll n;
	cin >> n;
	ll a[n+1], b[n+1], p[n];
	for(int i=0; i<n; i++) cin >> p[i];
	for(int i=1; i<=n; i++){
		a[i]=i*2*MAX;
		b[i]=MMAX-a[i];
	}
	for(int i=0; i<n; i++){
		b[p[i]]+=i;
	}

	for(int i=1; i<=n; i++) cout << a[i] << " ";
	cout << endl;
	for(int i=1; i<=n; i++) cout << b[i] << " ";
	cout << endl;

	return 0;
}