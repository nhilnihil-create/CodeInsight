#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m);
	for (int i=0; i<m; i++){
		cin >> a.at(i) >> b.at(i);
	}
	vector<int> ans(n);
	for(int i=0; i<m; i++){
		ans.at(a.at(i)-1)++;
		ans.at(b.at(i)-1)++;
	}
	for(int i=0; i<n; i++){
		cout << ans.at(i) << endl;
	}
}
