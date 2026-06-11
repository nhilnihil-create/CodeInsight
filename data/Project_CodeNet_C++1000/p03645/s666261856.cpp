#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n, m;

int main(void){
	cin >> n >> m;
	vector<bool> p(n+1), q(n+1);
	rep(i, m){
		lli a, b;
		cin >> a >> b;
		if(a == 1) p[b] = true;
		if(b == n) q[a] = true;
	}
	for(int i = 2; i <= n-1; i++){
		if(p[i] == true && q[i] == true){
			cout << "POSSIBLE" << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
