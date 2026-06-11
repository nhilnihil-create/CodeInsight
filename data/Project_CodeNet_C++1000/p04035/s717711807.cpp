#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, l;
	cin>>n>>l;
	int a[n + 1];
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	int ind = -1;
	for(int i = 1; i < n; i++){
		if(a[i] + a[i + 1] >= l){
			ind = i;
			break;
		}
	}
	if(ind == -1){
		cout<<"Impossible\n";
		exit(0);
	}
	cout<<"Possible\n";
	for(int i = 1; i < ind; i++){
		cout<<i<<'\n';
	}
	for(int i = n - 1; i > ind; i--){
		cout<<i<<'\n';
	}
	cout<<ind<<'\n';

	return 0;
}