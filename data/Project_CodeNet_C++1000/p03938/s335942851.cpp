#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	vector<int> p(n); for(int i = 0; i < n; i++) cin >> p[i];
	vector<int> a(n), pa(n), b(n), pb(n);
	for(int i = 0; i < n; i++) a[i] = i + 1, b[i] = n - i;
	int mk = 1;
	for(int i = n - 1; i >= 0; i--){
		p[i]--;
		int val = (i + 1) * mk;
		pa[p[i]] += val;
		pb[p[i]] += val;
	}
	for(int i = 0; i < n; i++){
		if(i) pa[i] += pa[i - 1];
		a[i] += pa[i];
	}
	for(int i = n - 1; i >= 0; i--){
		if(i != n - 1) pb[i] += pb[i + 1];
		b[i] += pb[i];
	}
	for(int v : a) cout << v << " "; cout << endl;
	for(int v : b) cout << v << " "; cout << endl;
	return 0;
}

