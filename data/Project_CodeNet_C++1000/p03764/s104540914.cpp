#include <iostream>
using namespace std;

typedef long long ll;
ll inf = 1e9+7;
ll n,m;
int main(){
	cin >> n >> m;
	ll X[n+1],Y[m+1];
	for(int i=1;i<=n;i++){
		cin >> X[i];
	}
	for(int i=1;i<=m;i++){
		cin >> Y[i];
	}
	ll x = 0, y = 0;
	for(ll i=1;i<=n;i++){
		x = (x + (i-1)*X[i] - (n-i)*X[i])%inf;
	}
	for(ll i=1;i<=m;i++){
		y = (y + (i-1)*Y[i] - (m-i)*Y[i])%inf;
	}
	cout << (x*y)%inf << endl;
}