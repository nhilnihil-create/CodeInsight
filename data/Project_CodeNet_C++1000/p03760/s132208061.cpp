#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string o, e;

int main(void){
	cin >> o >> e;
	int n, m;
	n = o.size();
	m = e.size();
	if(n-m == 1) e+='#';
	rep(i, n){
		cout << o[i];
		if(e[i] != '#') cout << e[i];
	}
	cout << endl;
	return 0;
}
